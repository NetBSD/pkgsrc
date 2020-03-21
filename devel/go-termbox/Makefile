# $NetBSD: Makefile,v 1.23 2020/03/21 16:57:14 bsiegert Exp $
#

DISTNAME=		go-termbox-20160808
PKGREVISION=		22
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=nsf/}
GITHUB_PROJECT=		termbox-go
GITHUB_TAG=		e8f6d27

HOMEPAGE=		http://godoc.org/${GO_SRCPATH}
COMMENT=		Pure Go termbox implementation
LICENSE=		mit

GO_SRCPATH=		github.com/nsf/termbox-go
# Skip building subdirectories (demos).
GO_BUILD_PATTERN=	${GO_SRCPATH}
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

REPLACE_PYTHON=		collect_terminfo.py

.include "../../textproc/go-runewidth/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
