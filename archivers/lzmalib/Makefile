# $NetBSD: Makefile,v 1.3 2010/05/16 00:43:18 obache Exp $
#

DISTNAME=	lzmalib-0.0.1
CATEGORIES=	archivers
MASTER_SITES=	http://tokyocabinet.sourceforge.net/misc/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://tokyocabinet.sourceforge.net/misc/
COMMENT=	Thin wrapper library of LZMA
#LICENSE=	gnu-lgpl-?

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	xz-[0-9]*

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

# Link with c++ instead (see also patch-aa)
CONFIGURE_ENV+=	ac_cv_lib_stdcpp_main=no

.include "../../mk/bsd.pkg.mk"
