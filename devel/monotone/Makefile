# $NetBSD: Makefile,v 1.3 2004/11/28 10:35:45 jmmv Exp $
#

DISTNAME=	monotone-0.15
CATEGORIES=	devel
MASTER_SITES=	http://www.venge.net/monotone/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.venge.net/monotone/
COMMENT=	Free distributed version control system

GNU_CONFIGURE=		yes
INFO_FILES=		monotone.info
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
USE_MAKEINFO=		yes

CONFIGURE_ARGS+=	--with-bundled-lua=no
CONFIGURE_ARGS+=	--with-bundled-sqlite=no
CONFIGURE_ENV+=		BOOST_TOOLSET=${BOOST_TOOLSET}

CPPFLAGS+=		-D__unix__ -D__unix

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../devel/boost/buildlink3.mk"
.include "../../devel/boost/toolset.mk"
.include "../../devel/boost-thread/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
