# $NetBSD: Makefile,v 1.9 2004/04/24 22:46:11 jlam Exp $
# FreeBSD Id: Makefile,v 1.5 1998/10/21 00:57:27 steve Exp
#

DISTNAME=		LPRng-3.6.26
PKGNAME=		LPRng-core-3.6.26
CATEGORIES=		print
MASTER_SITES=		ftp://ftp.astart.com/pub/LPRng/LPRng/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.lprng.com/
COMMENT=		Enhanced Printer Spooler

CONFLICTS+=		cups-[0-9]*

USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--sysconfdir="/etc"
CONFIGURE_ARGS+=	--with-lpd_perms_path="${LPD_PERMS_PATH}"
CONFIGURE_ARGS+=	--with-lpd_printcap_path="${LPD_PRINTCAP_PATH}"
CONFIGURE_ARGS+=	--with-printcap_path="${PRINTCAP_PATH}"
CONFIGURE_ARGS+=	--with-filterdir="${FILTER_DIR}"
CONFIGURE_ARGS+=	--with-filter_path="${FILTER_PATH}"
CONFIGURE_ARGS+=	--with-ld_library_path="${FILTER_LD_PATH}"

.include "../../mk/bsd.prefs.mk"

LPRNG_SUID?=		YES
LPRNG_PRIV_PORTS?=	NO
BUILD_DEFS+=		LPRNG_SUID LPRNG_PRIV_PORTS

.if (${LPRNG_SUID} == "NO")
CONFIGURE_ARGS+=	--disable-setuid
.endif
.if (${LPRNG_PRIV_PORTS} == "YES")
CONFIGURE_ARGS+=	--enable-priv_ports
.endif

# Look for printer configuration files firstly in /etc, then ${PREFIX}/etc.
#
LPD_PERMS_PATH=		/etc/lpd.perms:${PREFIX}/etc/lpd.perms
LPD_PRINTCAP_PATH=	/etc/lpd_printcap:${PREFIX}/etc/lpd_printcap
PRINTCAP_PATH=		/etc/printcap:${PREFIX}/etc/printcap
FILTER_DIR=		${PREFIX}/libexec/LPRng
FILTER_LD_PATH=		/usr/lib:${PREFIX}/lib:/usr/local/lib
FILTER_PATH=		${FILTER_DIR}:/sbin:/usr/sbin:/bin:/usr/bin:${PREFIX}/sbin:${PREFIX}/bin:/usr/local/sbin:/usr/local/bin

MAKE_ENV+=		POSTINSTALL="NO"

EXAMPLES_DIR=	 	${PREFIX}/share/examples/LPRng
DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

FILES_SUBST=		CAT=${CAT:Q}
FILES_SUBST+=		CHMOD=${CHMOD:Q}
FILES_SUBST+=		CMP=${CMP:Q}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		TRUE=${TRUE:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

pre-patch:
	${MV} ${WRKSRC}/man/lpd.conf.5 ${WRKSRC}/man/lpd.conf.5.in

post-configure:
	${SED}	-e "s,@FILTER_LD_PATH@,${FILTER_LD_PATH},g" \
		-e "s,@FILTER_PATH@,${FILTER_PATH},g" \
		-e "s,@LPD_PRINTCAP_PATH@,${LPD_PRINTCAP_PATH},g" \
		-e "s,@LPD_PERMS_PATH@,${LPD_PERMS_PATH},g" \
		-e "s,@PRINTCAP_PATH@,${PRINTCAP_PATH},g" \
		< ${WRKSRC}/man/lpd.conf.5.in > ${WRKSRC}/man/lpd.conf.5

pre-install:
	${SED}	-e "s,@PREFIX@,${PREFIX},g" \
		< ${FILESDIR}/LPRng.sh > ${WRKDIR}/LPRng.sh
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/LPRng.sh ${PREFIX}/etc/rc.d/LPRng
	${INSTALL_DATA_DIR} ${EXAMPLES_DIR}
	for file in lpd.conf lpd.perms printcap; do \
		${INSTALL_DATA} ${WRKSRC}/$${file} \
			${EXAMPLES_DIR}/$${file}.example; \
	done
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
