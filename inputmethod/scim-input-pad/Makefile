# $NetBSD: Makefile,v 1.40 2022/08/11 05:08:53 gutteridge Exp $
#

DISTNAME=	scim-input-pad-0.1.3
PKGREVISION=	30
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scim/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scim-im/scim
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
