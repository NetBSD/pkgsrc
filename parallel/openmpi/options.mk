# $NetBSD: options.mk,v 1.11 2022/08/25 22:09:14 thor Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openmpi
PKG_SUPPORTED_OPTIONS=	debug f90 java sge slurm
PKG_SUGGESTED_OPTIONS+=	f90

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

PLIST_VARS+=		f08 f90 java sge

.if !empty(PKG_OPTIONS:Mf90)
USE_LANGUAGES+=		fortran
GCC_REQD+=		4.7
CONFIGURE_ARGS+=	--enable-mpi-fortran=yes
# Enabling fortran builds for Fortran 90, and also for Fortran 08 if
# the toolchain is good enough.  In 2022, start by assuming that
# USE_LANGUAGES=fortran gets us a sufficiently modern compiler.
PLIST.f90=		yes
PLIST.f08=		yes
.else
CONFIGURE_ARGS+=	--enable-mpi-fortran=no
.endif

.if !empty(PKG_OPTIONS:Mjava)
CONFIGURE_ARGS+=	--enable-mpi-java
PLIST.java=		yes
.include "../../mk/java-vm.mk"
.else
CONFIGURE_ARGS+=	--disable-mpi-java
.endif

.if !empty(PKG_OPTIONS:Msge)
CONFIGURE_ARGS+=	--with-sge
PLIST.sge=		yes
.else
CONFIGURE_ARGS+=	--without-sge
.endif

.if !empty(PKG_OPTIONS:Mslurm)
CONFIGURE_ARGS+=	--with-slurm
.else
CONFIGURE_ARGS+=	--without-slurm
.endif
