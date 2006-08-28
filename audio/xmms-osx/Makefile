# $NetBSD: Makefile,v 1.2 2006/08/28 05:26:28 ben Exp $
#

DISTNAME=		xmms_osx_plugin-1.0
PKGNAME=		xmms-osx-1.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dbmix/}

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://dbmix.sourceforge.net/
COMMENT=		XMMS plugin for OSX native audio output

LDFLAGS+=		-lm
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	libtool-disable-static

PKG_INSTALLATION_TYPES=	overwrite pkgviews
ONLY_FOR_PLATFORM=	Darwin-*-*

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
