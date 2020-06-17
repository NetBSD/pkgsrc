# $NetBSD: Makefile,v 1.23 2020/06/17 09:54:03 bsiegert Exp $

DISTNAME=	emoji-1.4
PKGNAME=	go-${DISTNAME}
PKGREVISION=	19
MASTER_SITES=	${MASTER_SITE_GITHUB:=kyokomi/}
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kyokomi/emoji
COMMENT=	Emoji is a simple golang package
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/kyokomi/emoji

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
