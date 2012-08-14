# $NetBSD: Makefile,v 1.2 2012/08/14 07:02:09 wiz Exp $
#

DISTNAME=	celt-0.11.3
CATEGORIES=	audio
MASTER_SITES=	http://downloads.us.xiph.org/releases/celt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://downloads.us.xiph.org/releases/celt/
COMMENT=	Ultra-low-delay, high-quality audio codec (experimental)
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	celt.pc.in

.include "../../mk/bsd.prefs.mk"
.include "../../mk/oss.buildlink3.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "Solaris"
###
### XXX Remove this definition if DEVSUNAUDIO is placed in default mk.conf.
###
DEVSUNAUDIO?=		/dev/audio
BUILD_DEFS+=		DEVSUNAUDIO
CFLAGS+=		-DDEVSUNAUDIO=\"${DEVSUNAUDIO:U/dev/audio}\"
.elif ${OSS_TYPE} != "none"
MAKE_ENV+=		LIBOSSAUDIO=${LIBOSSAUDIO:Q}
CFLAGS+=		-DDEVOSSAUDIO=\"${DEVOSSAUDIO:U/dev/dsp}\"
.endif

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
