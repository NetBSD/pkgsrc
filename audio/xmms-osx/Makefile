# $NetBSD: Makefile,v 1.4 2010/03/08 00:47:08 snj Exp $
#

DISTNAME=		xmms_osx_plugin-1.0
PKGNAME=		xmms-osx-1.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dbmix/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://dbmix.sourceforge.net/
COMMENT=		XMMS plugin for OSX native audio output

LDFLAGS+=		-lm
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	libtool-disable-static

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_INSTALLATION_TYPES=	overwrite pkgviews
ONLY_FOR_PLATFORM=	Darwin-*-*

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
