# $NetBSD: Makefile,v 1.12 2022/06/27 15:29:14 fcambus Exp $

DISTNAME=	tio-1.40
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=tio/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tio/tio
COMMENT=	Simple TTY terminal I/O application
LICENSE=	gnu-gpl-v2

MESON_ARGS+=	-Dbashcompletiondir=${PREFIX}/share/bash-completion/completions

USE_TOOLS+=	pkg-config

.include "../../textproc/inih/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
