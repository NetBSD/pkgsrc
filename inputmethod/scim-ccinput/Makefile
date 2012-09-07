# $NetBSD: Makefile,v 1.13 2012/09/07 19:16:58 adam Exp $
#

DISTNAME=		scim-ccinput-0.3.1
PKGREVISION=		10
CATEGORIES=		inputmethod chinese
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scim/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://www.scim-im.org/
COMMENT=		SCIM IMEngine module for CCInput
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config bash msgfmt
CONFIG_SHELL=		${BASH}

USE_SCIM_GTKUTILS=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
