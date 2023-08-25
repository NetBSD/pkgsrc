# $NetBSD: Makefile,v 1.7 2023/08/25 15:52:52 vins Exp $

DISTNAME=	yash-2.55
CATEGORIES=	shells
MASTER_SITES=	http://osdn.dl.osdn.net/yash/79124/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://yash.osdn.jp/index.html.en
COMMENT=	POSIX-compliant command line shell
LICENSE=	gnu-gpl-v2

FORCE_C_STD=		c99

USE_TOOLS+=	msgfmt msgmerge
USE_TOOLS+=	intltool xgettext

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

PKG_SHELL=	bin/yash

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
