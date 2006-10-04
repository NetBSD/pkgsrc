# $NetBSD: Makefile,v 1.11 2006/10/04 21:36:01 wiz Exp $
#

DISTNAME=	tmake-1.13
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.trolltech.com/freebies/tmake/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.trolltech.com/developer/downloads/qt/freebies/
COMMENT=	Cross-platform Makefile Tool

USE_TOOLS+=	perl:run

TMAKEPATH=	${PREFIX}/lib/tmake/netbsd-g++
GLBASE=		${X11BASE}

INSTALLATION_DIRS=	bin

SUBST_CLASSES+=		tmake
SUBST_STAGE.tmake=	do-build
SUBST_FILES.tmake=	bin/tmake
SUBST_SED.tmake+=	-e 's;@TMAKEPATH@;'${TMAKEPATH:Q}';g'

SUBST_CLASSES+=		tmakeconf
SUBST_STAGE.tmakeconf=	do-build
SUBST_FILES.tmakeconf=	lib/netbsd-g++/tmake.conf
SUBST_SED.tmakeconf=	-e 's;@LOCALBASE@;${LOCALBASE};g'
SUBST_SED.tmakeconf+=	-e 's;@X11BASE@;${X11BASE};g'
SUBST_SED.tmakeconf+=	-e 's;@GLBASE@;${GLBASE};g'

REPLACE_PERL+=		bin/tmake bin/progen

# Nothing but the substitutions above.
do-build:
	@${DO_NADA}

# avoid installing .orig files
pre-install:
	${RM} -f ${WRKSRC}/lib/netbsd-g++/*.orig
	${RM} -f ${WRKSRC}/lib/unix/*.orig

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/progen ${PREFIX}/bin/progen
	${INSTALL_SCRIPT} ${WRKSRC}/bin/tmake ${PREFIX}/bin/tmake
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tmake
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/tmake
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/tmake
	${INSTALL_DATA} ${WRKSRC}/example/* ${PREFIX}/share/examples/tmake
	${INSTALL_DATA_DIR} ${PREFIX}/lib/tmake/netbsd-g++
	${INSTALL_DATA} ${WRKSRC}/lib/netbsd-g++/* ${PREFIX}/lib/tmake/netbsd-g++
	${INSTALL_DATA_DIR} ${PREFIX}/lib/tmake/unix
	${INSTALL_DATA} ${WRKSRC}/lib/unix/* ${PREFIX}/lib/tmake/unix

.include "../../mk/bsd.pkg.mk"
