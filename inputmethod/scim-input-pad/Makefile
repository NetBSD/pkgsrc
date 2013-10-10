# $NetBSD: Makefile,v 1.22 2013/10/10 14:42:19 ryoon Exp $
#

DISTNAME=	scim-input-pad-0.1.3
PKGREVISION=	14
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scim/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.scim-im.org/
COMMENT=	SCIM onscreen input pad
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake intltool pkg-config msgfmt

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
