# $NetBSD: Makefile,v 1.10 2024/06/09 07:44:54 vins Exp $

DISTNAME=	yash-2.56.1
CATEGORIES=	shells
MASTER_SITES=   ${MASTER_SITE_GITHUB:=magicant/}
GITHUB_RELEASE= ${PKGVERSION_NOREV}
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

USE_PKGLOCALEDIR=	yes

PKG_SHELL=	bin/yash

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
