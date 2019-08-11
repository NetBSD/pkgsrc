# $NetBSD: Makefile,v 1.23 2019/08/11 13:20:52 wiz Exp $
#

DISTNAME=	tmake-1.13
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.qtsoftware.com/freebies/tmake/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.qtsoftware.com/developer/downloads/qt/freebies/
COMMENT=	Cross-platform Makefile Tool

USE_TOOLS+=	perl:run

TMAKEPATH=	${PREFIX}/lib/tmake/netbsd-g++
GLBASE=		${X11BASE}

INSTALLATION_DIRS=	bin

SUBST_CLASSES+=		tmake
SUBST_STAGE.tmake=	do-build
SUBST_FILES.tmake=	bin/tmake
SUBST_VARS.tmake=	TMAKEPATH

SUBST_CLASSES+=		tmakeconf
SUBST_STAGE.tmakeconf=	do-build
SUBST_FILES.tmakeconf=	lib/netbsd-g++/tmake.conf
SUBST_VARS.tmakeconf=	LOCALBASE
SUBST_VARS.tmakeconf+=	X11BASE
SUBST_VARS.tmakeconf+=	GLBASE

REPLACE_PERL+=		bin/tmake bin/progen

# Nothing but the substitutions above.
do-build:
	@${DO_NADA}

# avoid installing .orig files
pre-install:
	${RM} -f ${WRKSRC}/lib/netbsd-g++/*.orig
	${RM} -f ${WRKSRC}/lib/unix/*.orig

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/progen ${DESTDIR}${PREFIX}/bin/progen
	${INSTALL_SCRIPT} ${WRKSRC}/bin/tmake ${DESTDIR}${PREFIX}/bin/tmake
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/tmake
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/tmake
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/tmake
	${INSTALL_DATA} ${WRKSRC}/example/* ${DESTDIR}${PREFIX}/share/examples/tmake
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/tmake/netbsd-g++
	${INSTALL_DATA} ${WRKSRC}/lib/netbsd-g++/* ${DESTDIR}${PREFIX}/lib/tmake/netbsd-g++
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/tmake/unix
	${INSTALL_DATA} ${WRKSRC}/lib/unix/* ${DESTDIR}${PREFIX}/lib/tmake/unix

.include "../../mk/bsd.pkg.mk"
