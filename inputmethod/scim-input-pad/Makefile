# $NetBSD: Makefile,v 1.31 2018/04/16 14:34:46 wiz Exp $
#

DISTNAME=	scim-input-pad-0.1.3
PKGREVISION=	22
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scim/}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
