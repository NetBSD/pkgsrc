# $NetBSD: Makefile,v 1.5 2015/03/15 17:30:24 hiramatsu Exp $
#

DISTNAME=	lzmalib-0.0.1
CATEGORIES=	archivers
MASTER_SITES=	http://tokyocabinet.sourceforge.net/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tokyocabinet.sourceforge.net/misc/
COMMENT=	Thin wrapper library of LZMA
#LICENSE=	gnu-lgpl-?

CONFLICTS=	xz-[0-9]*

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

# Link with c++ instead (see also patch-aa)
CONFIGURE_ENV+=	ac_cv_lib_stdcpp_main=no

.include "../../mk/bsd.pkg.mk"
