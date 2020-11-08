# $NetBSD: Makefile,v 1.32 2020/11/08 21:59:33 bsiegert Exp $
#

DISTNAME=		lf-13
PKGREVISION=		5
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

CHECK_RELRO_SKIP+=	bin/lf

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
