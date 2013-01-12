# $NetBSD: Makefile,v 1.13 2013/01/12 07:08:45 obache Exp $
#

DISTNAME=	m17n-contrib-1.1.14
CATEGORIES=	misc
MASTER_SITES=	http://download.savannah.gnu.org/releases//m17n/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/m17n/
COMMENT=	Collection of contributed works used with the m17n library
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	m17n-db<1.6.3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c

REPLACE_AWK=	tbl2mim.awk

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../misc/m17n-db/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
