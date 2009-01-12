# $NetBSD: Makefile,v 1.4 2009/01/12 12:22:54 obache Exp $
#

DISTNAME=	m17n-contrib-1.1.8
CATEGORIES=	misc
MASTER_SITES=	http://www.m17n.org/m17n-lib-download/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.m17n.org/m17n-lib/
COMMENT=	Collection of contributed works used with the m17n library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c

REPLACE_AWK=	tbl2mim.awk

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../misc/m17n-db/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
