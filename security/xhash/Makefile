# $NetBSD: Makefile,v 1.22.2.1 2026/04/22 14:32:14 maya Exp $

DISTNAME=	xhash-3.6.3
PKGREVISION=	10
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
