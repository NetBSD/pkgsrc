# $NetBSD: Makefile,v 1.7 2011/09/17 14:33:45 obache Exp $
#

DISTNAME=	scim-input-pad-0.1.3
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scim/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.scim-im.org/
COMMENT=	SCIM onscreen input pad
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake intltool pkg-config msgfmt

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
