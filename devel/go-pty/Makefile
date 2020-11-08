# $NetBSD: Makefile,v 1.7 2020/11/08 21:59:21 bsiegert Exp $

DISTNAME=	go-pty-1.1.11
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=creack/}
GITHUB_PROJECT=	pty
GITHUB_TAG=	v${PKGVERSION_NOREV}

COMMENT=	Go package for using unix pseudo-terminals
HOMEPAGE=	https://github.com/creack/pty
LICENSE=	mit
MAINTAINER=	pkgsrc-users@NetBSD.org

# for mktypes.bash
USE_TOOLS+=	bash
REPLACE_BASH+=	mktypes.bash
REPLACE_SH+=	test_crosscompile.sh

GO_SRCPATH=	github.com/creack/pty/
GO_DIST_BASE=	pty-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../devel/go-sys/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
