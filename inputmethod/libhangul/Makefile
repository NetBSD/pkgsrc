# $NetBSD: Makefile,v 1.12 2017/08/16 21:22:13 wiz Exp $

DISTNAME=	libhangul-0.1.0
CATEGORIES=	inputmethod korean
MASTER_SITES=	http://libhangul.googlecode.com/files/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/libhangul/
COMMENT=	Library used by Korean input methods
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	libhangul.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
