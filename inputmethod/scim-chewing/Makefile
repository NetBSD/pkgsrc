# $NetBSD: Makefile,v 1.14.2.1 2012/10/03 12:08:24 spz Exp $
#

DISTNAME=		scim-chewing-0.3.4
PKGREVISION=		7
CATEGORIES=		inputmethod
MASTER_SITES=		http://chewing.csie.net/download/scim/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://chewing.csie.net/
COMMENT=		SCIM IMEngine module for Chewing input method
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake msgfmt pkg-config intltool
GNU_CONFIGURE=		yes

USE_SCIM_GTKUTILS=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libchewing+=	libchewing>=0.3.3
.include "../../inputmethod/libchewing/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
