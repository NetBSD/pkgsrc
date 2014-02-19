# $NetBSD: options.mk,v 1.6 2014/02/19 09:44:56 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openmpi
PKG_SUPPORTED_OPTIONS=	debug f90

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif


.if !empty(PKG_OPTIONS:Mf90)
GCC_REQD+=		4.7
GCCDIR=			${PREFIX}/gcc47
CONFIGURE_ARGS+=	--enable-mpi-f90
CONFIGURE_ENV+=		FC=${GCCDIR}/bin/gfortran
PLIST_SRC+=		PLIST.f90

SUBST_CLASSES+=		f90
SUBST_STAGE.f90=	post-configure
SUBST_FILES.f90=	ompi/tools/wrappers/mpif90-wrapper-data.txt
SUBST_SED.f90=		-e 's,^compiler=.*$$,compiler=${GCCDIR}/bin/gfortran,'
SUBST_SED.f90+=		-e 's,^linker_flags=,linker_flags= -R${GCCDIR}/lib ,'
SUBST_SED.f90+=		-e 's,^linker_flags=,linker_flags= -L${GCCDIR}/lib ,'
.else
CONFIGURE_ARGS+=	--disable-mpi-f90
.endif

PLIST_SRC+=		PLIST
