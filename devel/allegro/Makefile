# $NetBSD: Makefile,v 1.1.1.1 2004/04/05 05:02:41 xtraeme Exp $
#

DISTNAME=	allegro-4.1.13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=alleg/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://alleg.sourceforge.net/
COMMENT=	Allegro game programming library

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
GNU_CONFIGURE=		yes

MAKEFILE=		makefile
ALL_TARGET=		# there is no 'all' target for some reason
USE_MAKEINFO=		yes
INFO_FILES=		allegro.info
INSTALL_TARGET=		install install-info

# NetBSD's OSS midi emulation is non-existant.
CONFIGURE_ARGS+=	--disable-ossmidi

LIBS+=		${LIBOSSAUDIO}
CFLAGS+=	-DDEVOSSAUDIO=\"\\\"${DEVOSSAUDIO}\\\"\"

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	USE_ESOUND

.if !empty(USE_ESOUND:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-esddigi
.include "../../audio/esound/buildlink3.mk"
.endif

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
