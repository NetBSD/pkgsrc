# $NetBSD: Makefile,v 1.3 2018/03/30 11:56:25 bsiegert Exp $

DISTNAME=	hub-2.2.9
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=github/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://hub.github.com/
COMMENT=	hub helps you win at git
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/github/hub

DEPENDS+=		git-base>=1.7.3:../../devel/git-base

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fix hub name in hub(1) man page
SUBST_FILES.man=	man/hub.1
SUBST_SED.man+=		-e 's/\\fBgit/\\fBhub/g'
SUBST_SED.man+=		-e 's/\$$ git/$$ hub/'
SUBST_SED.man+=		-e '/\$$ GITHUB_HOST=/ s/ git clone / hub clone /'
SUBST_SED.man+=		-e 's/\.SS "git/.SS "hub/'

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

CHECK_RELRO_SKIP+=	bin/hub

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/hub ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/hub.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
