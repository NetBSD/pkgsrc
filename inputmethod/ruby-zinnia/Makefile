# $NetBSD: Makefile,v 1.4 2012/10/06 14:25:15 asau Exp $
#

.include "../../inputmethod/zinnia/Makefile.common"

PKGREVISION=	1
CATEGORIES+=	ruby

COMMENT=	Zinnia ruby module

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF_SUBDIRS=	ruby

BUILDLINK_API_DEPENDS.zinnia+=	zinnia>=${PKGVERSION_NOREV}
.include "../../inputmethod/zinnia/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
