# $NetBSD: Makefile,v 1.28 2020/11/13 19:26:07 bsiegert Exp $

DISTNAME=	fsnotify-1.3.0
PKGNAME=	go-${DISTNAME}
PKGREVISION=	25
MASTER_SITES=	${MASTER_SITE_GITHUB:=fsnotify/}
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fsnotify/fsnotify
COMMENT=	File system notifications for Go
# LICENSE=	XXX

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/fsnotify/fsnotify

.include "../../devel/go-sys/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
