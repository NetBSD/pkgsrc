# $NetBSD: Makefile,v 1.7 2009/11/01 08:47:23 obache Exp $

DISTNAME=	libhangul-0.0.10
CATEGORIES=	inputmethod korean
MASTER_SITES=	http://kldp.net/frs/download.php/5417/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://kldp.net/projects/hangul/
COMMENT=	Library used by Korean input methods

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libhangul.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
