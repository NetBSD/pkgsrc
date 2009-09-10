# $NetBSD: Makefile,v 1.1.1.1 2009/09/10 20:16:44 wiz Exp $
#

DISTNAME=	bml-0.5.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=buzztard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://buzztard.sourceforge.net/
COMMENT=	Buzz machine loader
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libbml.pc.in

BUILDLINK_TRANSFORM+=	rm:-ldl

.include "../../mk/bsd.pkg.mk"
