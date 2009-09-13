# $NetBSD: hacks.mk,v 1.1 2009/09/13 16:12:18 tron Exp $

.if !defined(SCUMMVM_HACKS_MK)
SCUMMVM_HACKS_MK=	defined

.include "../../mk/bsd.fast.prefs.mk"

# scummvm used an API that no longer exists under Mac OS X Snow Leopard.
# Work around that by using the Leopard SDK which is part of Xcode tools.

XCODE_LEOPARD_SDK=	/Developer/SDKs/MacOSX10.5.sdk

.if !empty(MACHINE_PLATFORM:MDarwin-??.*-*) && \
    exists(/Developer/SDKs/MacOSX10.5.sdk)
PKG_HACKS+=	scummvm-snow-leopard

CFLAGS+=	-mmacosx-version-min=10.5 -isysroot ${XCODE_LEOPARD_SDK}
LDFLAGS+=	-mmacosx-version-min=10.5 -Wl,-syslibroot,${XCODE_LEOPARD_SDK}
.endif

.endif	# SCUMMVM_HACKS_MK
