# $NetBSD: Makefile,v 1.5 2005/05/15 04:26:24 jlam Exp $
#

DISTNAME=	majesty_demo
PKGNAME=	majesty-demo-20030310
CATEGORIES=	games
MASTER_SITES=	http://demos.linuxgamepublishing.com/majesty/
EXTRACT_SUFX=	.run

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://majesty.linuxgamepublishing.com/
COMMENT=	Fantasy kingdom simulation (demo)

EXTRACT_CMD=	${SED} '1,/^END_OF_STUB$$/d' ${DOWNLOADED_DISTFILE} | \
			${GZCAT} | ${PAX} -O -r
PKGSRC_USE_TOOLS+=	gzcat pax

ONLY_FOR_PLATFORM=*-*-i386

WRKSRC=		${WRKDIR}

.if (${MACHINE_ARCH} == "i386")
DEPENDS+=       suse_x11>=6.3:../../emulators/${SUSE_DIR_PREFIX}_x11
.endif

BINNAME=	maj_demo
LGP_PATH=	${PREFIX}/lib/lgp
MAJ_PATH=	${LGP_PATH}/maj_demo

do-build:
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	       -e 's#@@LIBDIR@@#${MAJ_PATH}#g' \
	       -e 's#@@BINNAME@@#${BINNAME}#g' \
	    <${FILESDIR}/wrapper.sh >${WRKDIR}/${BINNAME}.sh

do-install:
	${INSTALL_DATA_DIR} ${LGP_PATH}
	${INSTALL_DATA_DIR} ${MAJ_PATH}
	${INSTALL_PROGRAM} ${WRKDIR}/bin/Linux/x86/glibc-2.1/maj_demo \
		${MAJ_PATH}
	cd ${WRKDIR} && ${PAX} -rw README README.licenses data majesty* \
		quests ${MAJ_PATH}
	${INSTALL_SCRIPT} ${WRKDIR}/${BINNAME}.sh ${PREFIX}/bin/${BINNAME}

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
