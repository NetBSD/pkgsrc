# $NetBSD: Makefile,v 1.10 2020/03/20 11:58:08 nia Exp $

DISTNAME=	libquvi-scripts-0.4.21
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quvi/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://quvi.sourceforge.net/
COMMENT=	Scripts for libquvi
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	quvi<=0.2.19

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none

CONFIGURE_ARGS+=	--with-nsfw

PKGCONFIG_OVERRIDE+=	libquvi-scripts.pc.in

.include "../../mk/bsd.pkg.mk"
