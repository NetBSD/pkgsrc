# $NetBSD: Makefile,v 1.3 2011/02/21 16:01:18 taca Exp $
#

.include "../../inputmethod/zinnia/Makefile.common"

PKGREVISION=	1
CATEGORIES+=	ruby

COMMENT=	Zinnia ruby module

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF_SUBDIRS=	ruby

BUILDLINK_API_DEPENDS.zinnia+=	zinnia>=${PKGVERSION_NOREV}
.include "../../inputmethod/zinnia/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
