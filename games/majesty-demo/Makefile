# $NetBSD: Makefile,v 1.1.1.1 2003/06/19 16:44:07 wiz Exp $
#

DISTNAME=	majesty_demo
PKGNAME=	majesty-demo-20030310
WRKSRC=		${WRKDIR}
CATEGORIES=	games
MASTER_SITES=	http://demos.linuxgamepublishing.com/majesty/
EXTRACT_SUFX=	.run

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://majesty.linuxgamepublishing.com/
COMMENT=	fantasy kingdom simulation (demo)

EXTRACT_CMD=	${SED} '1,/^END_OF_STUB$$/d' ${DOWNLOADED_DISTFILE} | \
			${GZCAT} | ${PAX} -O -r

ONLY_FOR_PLATFORM=*-*-i386

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
