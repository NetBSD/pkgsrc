# $NetBSD: Makefile,v 1.8 2011/02/27 09:06:34 obache Exp $

DISTNAME=	libhangul-0.0.12
CATEGORIES=	inputmethod korean
MASTER_SITES=	http://kldp.net/frs/download.php/5855/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://kldp.net/projects/hangul/
COMMENT=	Library used by Korean input methods
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libhangul.pc.in
GNU_CONFIGURE=		yes

BROKEN_GETTEXT_DETECTION=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
