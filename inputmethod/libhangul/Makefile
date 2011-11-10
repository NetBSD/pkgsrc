# $NetBSD: Makefile,v 1.10 2011/11/10 10:40:11 obache Exp $

DISTNAME=	libhangul-0.1.0
CATEGORIES=	inputmethod korean
MASTER_SITES=	http://libhangul.googlecode.com/files/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libhangul/
COMMENT=	Library used by Korean input methods
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	libhangul.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
