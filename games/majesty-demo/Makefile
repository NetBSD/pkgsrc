# $NetBSD: Makefile,v 1.17 2013/04/06 12:04:00 rodent Exp $
#

DISTNAME=	majesty_demo
PKGNAME=	majesty-demo-20030310
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://demos.linuxgamepublishing.com/majesty/
EXTRACT_SUFX=	.run

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.linuxgamepublishing.com/info.php?id=majesty
COMMENT=	Fantasy kingdom simulation (demo)

EXTRACT_CMD=	${SED} '1,/^END_OF_STUB$$/d' $$extract_file | \
			${GZCAT} | pax -O -r
USE_TOOLS+=	gzcat pax

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	x11

WRKSRC=		${WRKDIR}
BUILD_DIRS=	# empty

BINNAME=	maj_demo
LGP_PATH=	${PREFIX}/lib/lgp
MAJ_PATH=	${LGP_PATH}/maj_demo

INSTALLATION_DIRS=	bin

do-build:
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	       -e 's#@@LIBDIR@@#${MAJ_PATH}#g' \
	       -e 's#@@BINNAME@@#${BINNAME}#g' \
	    <${FILESDIR}/wrapper.sh >${WRKDIR}/${BINNAME}.sh

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${LGP_PATH}
	${INSTALL_DATA_DIR} ${DESTDIR}${MAJ_PATH}
	${INSTALL_PROGRAM} ${WRKDIR}/bin/Linux/x86/glibc-2.1/maj_demo \
		${DESTDIR}${MAJ_PATH}
	cd ${WRKDIR} && pax -rw README README.licenses data majesty* \
		quests ${DESTDIR}${MAJ_PATH}
	${INSTALL_SCRIPT} ${WRKDIR}/${BINNAME}.sh \
		${DESTDIR}${PREFIX}/bin/${BINNAME}

.include "../../mk/bsd.pkg.mk"
