# $NetBSD: Makefile,v 1.46 2022/02/13 19:24:28 bsiegert Exp $
#

DISTNAME=		lf-13
PKGREVISION=		18
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=gokcehan/}
GITHUB_TAG=		r13

HOMEPAGE=		https://${GO_SRCPATH}
COMMENT=		Terminal file manager
LICENSE=		2-clause-bsd

GO_MODULE_FILES+=	github.com/mattn/go-runewidth/@v/v0.0.4.mod
GO_MODULE_FILES+=	github.com/mattn/go-runewidth/@v/v0.0.4.zip
GO_MODULE_FILES+=	github.com/nsf/termbox-go/@v/v0.0.0-20190325093121-288510b9734e.zip
GO_MODULE_FILES+=	github.com/nsf/termbox-go/@v/v0.0.0-20190325093121-288510b9734e.mod

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
