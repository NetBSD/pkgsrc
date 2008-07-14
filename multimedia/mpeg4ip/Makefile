# $NetBSD: Makefile,v 1.15 2008/07/14 12:56:09 joerg Exp $

DISTNAME=		mpeg4ip-1.5.0.1
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mpeg4ip/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mpeg4ip.sourceforge.net/
COMMENT=		Tools for streaming video and audio

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		faad2<2.0nb6

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	bootstrap
OVERRIDE_DIRDEPTH=	3		# */*/*/libtool

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		mpeg4ipSDL
.if ${OPSYS} != "Darwin"
PLIST.mpeg4ipSDL=	yes
.endif

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
