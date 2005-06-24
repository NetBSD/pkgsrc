# $NetBSD: Makefile,v 1.19 2005/06/24 19:05:48 kristerw Exp $

DISTNAME=	LPRng-3.8.28
PKGNAME=	LPRng-core-3.8.28
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.lprng.com/pub/LPRng/LPRng/ \
		http://www.lprng.com/DISTRIB/LPRng/ \
		http://lprng.sourceforge.net/DISTRIB/LPRng/
EXTRACT_SUFX=	.tgz

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.lprng.com/
COMMENT=	Enhanced Printer Spooler

CONFLICTS+=		cups-[0-9]*

USE_TOOLS+=		chgrp chown gmake
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-lpd_perms_path="${LPD_PERMS_PATH}"
CONFIGURE_ARGS+=	--with-lpd_printcap_path="${LPD_PRINTCAP_PATH}"
CONFIGURE_ARGS+=	--with-printcap_path="${PRINTCAP_PATH}"
CONFIGURE_ARGS+=	--with-filterdir="${FILTER_DIR}"
CONFIGURE_ARGS+=	--with-filter_path="${FILTER_PATH}"
CONFIGURE_ARGS+=	--with-ld_library_path="${FILTER_LD_PATH}"
CONFIGURE_ENV+=		CHGRP="${TOOLS_CHGRP}"
CONFIGURE_ENV+=		CHOWN="${TOOLS_CHOWN}"

.include "options.mk"

# Look for printer configuration files firstly in /etc, then ${PREFIX}/etc.
#
LPD_PERMS_PATH=		${PKG_SYSCONFDIR}/lpd/lpd.perms
LPD_PRINTCAP_PATH=	${PKG_SYSCONFDIR}/printcap
PRINTCAP_PATH=		${PKG_SYSCONFDIR}/printcap
FILTER_DIR=		${PREFIX}/libexec/LPRng
FILTER_LD_PATH=		/usr/lib:${PREFIX}/lib:/usr/local/lib
FILTER_PATH=		${FILTER_DIR}:/sbin:/usr/sbin:/bin:/usr/bin:${PREFIX}/sbin:${PREFIX}/bin:/usr/local/sbin:/usr/local/bin

MAKE_ENV+=		POSTINSTALL="NO"

EXAMPLESDIR=	 	${PREFIX}/share/examples/LPRng
DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL
USE_PKGINSTALL=		YES
RCD_SCRIPTS=		LPRng

FILES_SUBST=		CAT=${CAT:Q}
FILES_SUBST+=		CHMOD=${CHMOD:Q}
FILES_SUBST+=		CMP=${CMP:Q}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		MKDIR=${MKDIR:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		TRUE=${TRUE:Q}
FILES_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

pre-patch:
	${MV} ${WRKSRC}/man/lpd.conf.n ${WRKSRC}/man/lpd.conf.n.in

post-configure:
	${SED}	-e "s,@FILTER_LD_PATH@,${FILTER_LD_PATH},g" \
		-e "s,@FILTER_PATH@,${FILTER_PATH},g" \
		-e "s,@LPD_PRINTCAP_PATH@,${LPD_PRINTCAP_PATH},g" \
		-e "s,@LPD_PERMS_PATH@,${LPD_PERMS_PATH},g" \
		-e "s,@PRINTCAP_PATH@,${PRINTCAP_PATH},g" \
		-e "s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g" \
		< ${WRKSRC}/man/lpd.conf.n.in > ${WRKSRC}/man/lpd.conf.n

pre-install:
	${SED}	-e "s,@PREFIX@,${PREFIX},g" \
		< ${FILESDIR}/LPRng.sh > ${WRKDIR}/LPRng.sh
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	for file in lpd.conf lpd.perms printcap; do \
		${INSTALL_DATA} ${WRKSRC}/$${file} \
			${EXAMPLESDIR}/$${file}.example; \
	done
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
