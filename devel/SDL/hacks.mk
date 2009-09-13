# $NetBSD: hacks.mk,v 1.1 2009/09/13 15:51:47 tron Exp $

.if !defined(SDL_HACKS_MK)
SDL_HACKS_MK=	defined

.include "../../mk/bsd.fast.prefs.mk"

# SDL doesn't build with the API's provided by Mac OS X Snow Leopard:
#
# http://www.mail-archive.com/fink-users@lists.sourceforge.net/msg30617.html
#
# Work around that by using the Leopard SDK which is part of Xcode.

XCODE_LEOPARD_SDK=	/Developer/SDKs/MacOSX10.5.sdk

.if !empty(MACHINE_PLATFORM:MDarwin-??.*-*) && \
    exists(/Developer/SDKs/MacOSX10.5.sdk)
PKG_HACKS+=	sdl-snow-leopard

CFLAGS+=	-mmacosx-version-min=10.5 -isysroot ${XCODE_LEOPARD_SDK}
LDFLAGS+=	-mmacosx-version-min=10.5 -Wl,-syslibroot,${XCODE_LEOPARD_SDK}
.endif

.endif	# SDL_HACKS_MK
