# $NetBSD: Makefile,v 1.15 2026/04/20 18:36:04 vins Exp $

DISTNAME=	yash-2.61
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=magicant/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://magicant.github.io/yash/
COMMENT=	POSIX-compliant command line shell
LICENSE=	gnu-gpl-v2

FORCE_C_STD=		c99

USE_TOOLS+=		msgfmt msgmerge
USE_TOOLS+=		intltool xgettext

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--disable-doc

USE_PKGLOCALEDIR=	yes

PKG_SHELL=	bin/yash

TEST_TARGET=	test

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
