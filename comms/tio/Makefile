# $NetBSD: Makefile,v 1.5 2022/02/20 08:34:39 fcambus Exp $

DISTNAME=	tio-1.35
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=tio/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://github.com/tio/tio
COMMENT=	Simple TTY terminal I/O application
LICENSE=	gnu-gpl-v2

MESON_ARGS+=	-Dbashcompletiondir=${PREFIX}/share/bash-completion/completions

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
