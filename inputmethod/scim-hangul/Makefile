# $NetBSD: Makefile,v 1.7 2011/11/01 06:01:54 sbd Exp $
#

DISTNAME=		scim-hangul-0.3.2
PKGREVISION=		6
CATEGORIES=		inputmethod korean
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scim/}

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://www.scim-im.org/
COMMENT=		SCIM IMEngine module for inputing korean scripts
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt pkg-config gmake
GNU_CONFIGURE=		yes

USE_SCIM_GTKUTILS=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/libhangul/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
