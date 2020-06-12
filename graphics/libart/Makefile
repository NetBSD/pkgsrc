# $NetBSD: Makefile,v 1.9 2020/06/12 14:31:12 ryoon Exp $

DISTNAME=		libart_lgpl-2.3.21
PKGNAME=		${DISTNAME:S/_lgpl//}
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libart_lgpl/2.3/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.levien.com/libart/
COMMENT=		High-performance 2D graphics library
LICENSE=		gnu-lgpl-v2

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	libart-2.0.pc.in
# bmake cannot handle the self-made libtool logic in Makefile.am.
USE_TOOLS+=		gmake
CONFLICTS+=		libart2-[0-9]*

.include "../../mk/bsd.pkg.mk"
