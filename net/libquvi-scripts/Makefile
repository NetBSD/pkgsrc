# $NetBSD: Makefile,v 1.11 2022/07/25 11:12:27 wiz Exp $

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
USE_LANGUAGES=	# none

CONFIGURE_ARGS+=	--with-nsfw

PKGCONFIG_OVERRIDE+=	libquvi-scripts.pc.in

.include "../../mk/bsd.pkg.mk"
