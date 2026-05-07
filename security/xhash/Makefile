# $NetBSD: Makefile,v 1.24 2026/05/07 18:50:06 bsiegert Exp $

DISTNAME=	xhash-3.6.3
PKGREVISION=	11
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=ricardobranco777/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	rbranco@suse.de
HOMEPAGE=	https://github.com/ricardobranco777/xhash
COMMENT=	Faster hashing with Goroutines
LICENSE=	mit

GO_VERSION_REQD=	124

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/xhash.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
