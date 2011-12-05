# $NetBSD: Makefile,v 1.2 2011/12/05 19:34:12 ryoon Exp $
#

DISTNAME=	libquvi-scripts-0.4.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quvi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://quvi.sourceforge.net/
COMMENT=	Scripts for libquvi
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	quvi<=0.2.19

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none

CONFIGURE_ARGS+=	--with-nsfw

PKGCONFIG_OVERRIDE+=	libquvi-scripts.pc.in

.include "../../mk/bsd.pkg.mk"
