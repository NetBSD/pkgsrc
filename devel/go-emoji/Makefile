# $NetBSD: Makefile,v 1.26 2020/09/03 07:29:42 bsiegert Exp $

DISTNAME=	emoji-1.4
PKGNAME=	go-${DISTNAME}
PKGREVISION=	22
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
