# $NetBSD: Makefile,v 1.30 2019/08/14 15:45:45 bsiegert Exp $

DISTNAME=	hub-2.12.3
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=github/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://hub.github.com/
COMMENT=	Command-line tool that makes git easier to use with GitHub
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/github/hub

DEPENDS+=		git-base>=1.7.3:../../devel/git-base

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fix hub name in hub(1) man page
SUBST_FILES.man=	share/man/man1/hub.1.md
SUBST_SED.man+=		-e 's/\$$ git/$$ hub/'
SUBST_SED.man+=		-e '/\$$ GITHUB_HOST=/ s/ git clone / hub clone /'

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

CHECK_RELRO_SKIP+=	bin/hub

# Generate hub(1) man page
pre-install:
	cd ${WRKDIR} && \
	    ./bin/md2roff-bin --manual="hub manual" \
		--version=${PKGVERSION_NOREV} \
		--template=src/github.com/github/hub/man-template.html \
		src/github.com/github/hub/share/man/man1/hub.1.md

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/hub ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/share/man/man1/hub.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
