# $NetBSD: Makefile,v 1.26 2014/05/05 00:48:03 ryoon Exp $
#

DISTNAME=		scim-chewing-0.3.5
PKGREVISION=		3
CATEGORIES=		inputmethod
MASTER_SITES=		http://chewing.googlecode.com/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://chewing.im/
COMMENT=		SCIM IMEngine module for Chewing input method
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake msgfmt pkg-config intltool
GNU_CONFIGURE=		yes

USE_SCIM_GTKUTILS=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libchewing+=	libchewing>=0.3.4
.include "../../inputmethod/libchewing/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
