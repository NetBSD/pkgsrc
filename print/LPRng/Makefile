# $NetBSD: Makefile,v 1.3 2000/04/19 19:47:24 nathanw Exp $
# FreeBSD Id: Makefile,v 1.5 1998/10/21 00:57:27 steve Exp
#

DISTNAME=	LPRng-3.6.8
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.astart.com/pub/LPRng/LPRng/
EXTRACT_SUFX=	.tgz
DISTFILES=	${LPRNG_SRC} ${LPRNG_DOC}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.astart.com/LPRng.html

LPRNG_SRC=	${DISTNAME}${EXTRACT_SUFX}
LPRNG_DOC=	${DISTNAME:S/-/_DOC-/}${EXTRACT_SUFX}
EXTRACT_ONLY=	${LPRNG_SRC}

BUILD_DEFS+=	LPRNG_SUID LPRNG_PRIV_PORTS

MAKEFILE=		Makefile.bsd
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${LPRNG_SYSCONFDIR} \
			--with-filterdir=${FILTER_DIR}

.include "../../mk/bsd.prefs.mk"

LPRNG_SUID?=		YES
LPRNG_PRIV_PORTS?=	NO

.if (${LPRNG_SUID} == "NO")
CONFIGURE_ARGS+=	--disable-setuid
.endif
.if (${LPRNG_PRIV_PORTS} == "YES")
CONFIGURE_ARGS+=	--enable-priv_ports
.endif

LPRNG_SYSCONFDIR=	/etc
LPD_PRINTCAP_PATH=	${LPRNG_SYSCONFDIR}/lpd_printcap,${PREFIX}/etc/lpd_printcap
LPD_PERMS_PATH=		${LPRNG_SYSCONFDIR}/lpd.perms
PRINTCAP_PATH=		${LPRNG_SYSCONFDIR}/printcap

FILTER_DIR=		${PREFIX}/libexec/LPRng
FILTER_LD_PATH=		/usr/lib:${PREFIX}/lib:/usr/local/lib
FILTER_PATH=		${FILTER_DIR}:/sbin:/usr/sbin:/bin:/usr/bin:${PREFIX}/sbin:${PREFIX}/bin:/usr/local/sbin:/usr/local/bin

MAKE_ENV+=	FILTER_LD_PATH="${FILTER_LD_PATH}" \
		FILTER_PATH="${FILTER_PATH}" \
		LPD_PRINTCAP_PATH="${LPD_PRINTCAP_PATH}"

pre-patch:
	${MV} ${WRKSRC}/man/lpd.conf.5 ${WRKSRC}/man/lpd.conf.5.in

post-configure:
	${SED}	-e "s#@@FILTER_LD_PATH@@#${FILTER_LD_PATH}#g" \
		-e "s#@@FILTER_PATH@@#${FILTER_PATH}#g" \
		-e "s#@@LPD_PRINTCAP_PATH@@#${LPD_PRINTCAP_PATH}#g" \
		-e "s#@@LPD_PERMS_PATH@@#${LPD_PERMS_PATH}#g" \
		-e "s#@@PRINTCAP_PATH@@#${PRINTCAP_PATH}#g" \
		${WRKSRC}/man/lpd.conf.5.in > ${WRKSRC}/man/lpd.conf.5

post-install:
	${SED}	-e "s#@@PREFIX@@#${PREFIX}#g" \
		-e "s#@@CAT@@#${CAT}#g" \
		-e "s#@@ECHO@@#${ECHO}#g" \
		${FILESDIR}/lprng.sh > ${WRKDIR}/lprng.sh
	${INSTALL_SCRIPT} ${WRKDIR}/lprng.sh ${PREFIX}/etc/rc.d/lprng.sh

	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/LPRng
	${PAX}	-rzf ${DISTDIR}/${LPRNG_DOC} \
		-s "#^${DISTNAME:S/-/_DOC-/}/#${PREFIX}/share/doc/LPRng/#" \
		'*.gif' '*.html' '*.ps' '*.txt'

.include "../../mk/bsd.pkg.mk"
