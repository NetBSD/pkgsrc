# $NetBSD: Makefile,v 1.13 2023/09/16 09:54:03 bsiegert Exp $

DISTNAME=	tio-2.6
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
