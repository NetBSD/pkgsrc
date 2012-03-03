# $NetBSD: Makefile,v 1.13 2012/03/03 00:13:23 wiz Exp $
#

DISTNAME=	scim-bridge-0.4.16
PKGREVISION=	11
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scim/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.scim-im.org/projects/scim_bridge
COMMENT=	C wrapper library for SCIM
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--enable-agent
CONFIGURE_ARGS+=	--disable-documents
CONFIGURE_ARGS+=	--disable-tests

.include "options.mk"

CHECK_PORTABILITY_SKIP=	tests/*

.include "../../inputmethod/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
