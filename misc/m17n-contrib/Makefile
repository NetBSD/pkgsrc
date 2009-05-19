# $NetBSD: Makefile,v 1.6 2009/05/19 08:59:24 wiz Exp $
#

DISTNAME=	m17n-contrib-1.1.9
CATEGORIES=	misc
MASTER_SITES=	http://www.m17n.org/m17n-lib-download/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.m17n.org/m17n-lib/
COMMENT=	Collection of contributed works used with the m17n library
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c

REPLACE_AWK=	tbl2mim.awk

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../misc/m17n-db/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
