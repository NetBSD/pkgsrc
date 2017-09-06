# $NetBSD: Makefile,v 1.27 2017/09/06 09:03:01 wiz Exp $
#

DISTNAME=	tkdiff-4.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tkdiff/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/tkdiff/
COMMENT=	Graphical 2-way diff/merge tool

NO_BUILD=	yes
NO_CONFIGURE=	yes
USE_TOOLS+=	wish:run
WRKSRC=		${WRKDIR}/tkdiff-unix

SUBST_CLASSES+=		wish
SUBST_MESSAGE.wish=	Fixing a hardcoded command.
SUBST_STAGE.wish=	pre-configure
SUBST_FILES.wish=	tkdiff
SUBST_SED.wish=		-e 's,exec wish,exec ${WISH},'

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkdiff ${DESTDIR}${PREFIX}/bin/tkdiff4

.include "../../mk/bsd.pkg.mk"
