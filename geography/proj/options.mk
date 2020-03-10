# $NetBSD: options.mk,v 1.1 2020/03/10 16:17:38 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.proj

PKG_SUPPORTED_OPTIONS=	proj-grids
PKG_SUGGESTED_OPTIONS=	proj-grids

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		grids

.if !empty(PKG_OPTIONS:Mproj-grids)
DISTFILES+=	proj-datumgrid-1.8${EXTRACT_SUFX}
DISTFILES+=	proj-datumgrid-europe-1.5${EXTRACT_SUFX}
DISTFILES+=	proj-datumgrid-north-america-1.3${EXTRACT_SUFX}
DISTFILES+=	proj-datumgrid-oceania-1.1${EXTRACT_SUFX}
DISTFILES+=	proj-datumgrid-world-1.0${EXTRACT_SUFX}

PLIST.grids=		yes
.else
.endif
