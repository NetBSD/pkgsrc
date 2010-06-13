# $NetBSD: Makefile,v 1.2 2010/06/13 22:44:49 wiz Exp $
#

DISTNAME=	scim-array-1.0.1
PKGREVISION=	1
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://of.openfoundry.org/download/scimarray/1.0.1/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://scimarray.openfoundry.org/index_en.html
COMMENT=	Array 30 Input Method Engine for SCIM
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		msgfmt pkg-config

USE_SCIM_GTKUTILS=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
