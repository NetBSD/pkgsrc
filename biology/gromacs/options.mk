# $NetBSD: options.mk,v 1.2 2010/05/16 12:04:03 asau Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gromacs
PKG_SUPPORTED_OPTIONS+=		mpi x11
PKG_SUGGESTED_OPTIONS+=		mpi x11

.include "../../mk/bsd.options.mk"

PLIST_VARS=	x11

# MPI support:
.if !empty(PKG_OPTIONS:Mmpi)
CONFIGURE_ARGS+=	--enable-mpi
PLIST_SUBST+=		MPI=_mpi
.include "../../mk/mpi.buildlink3.mk"
.else
PLIST_SUBST+=		MPI=
.endif

# X support:
.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
PLIST.x11=	yes

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.endif
