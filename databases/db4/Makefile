# $NetBSD: Makefile,v 1.23 2004/10/03 00:13:18 tv Exp $

DISTNAME=		db-4.2.52
PKGNAME=		${DISTNAME:S/db/db4/}
PKGREVISION=		5
CATEGORIES=		databases
MASTER_SITES=		http://www.sleepycat.com/update/snapshot/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.sleepycat.com/
COMMENT=		Berkeley DB version 4 from Sleepycat Software

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME}/build_unix
USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure

CONFIGURE_ARGS+=	--enable-cxx
CONFIGURE_ARGS+=	--enable-rpc
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-compat185
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/db4
CONFIGURE_ARGS+=	--program-transform-name=s,db_,db4_,

# NetBSD-sparc64-1.6*'s f77 makes configure failing and as f77 is not
# needed for this package the following does no harm on other platform.
CONFIGURE_ENV+=		F77=${FALSE}

.if ${MACHINE_ARCH} == "powerpc"
.  include "../../mk/compiler.mk"
.  if !empty(CC_VERSION:Mgcc*)
.    if !defined(_GCC_IS_TOO_OLD)
_GCC_IS_TOO_OLD!=	\
	if ${PKG_ADMIN} pmatch 'gcc<3.3' ${CC_VERSION}; then		\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
MAKEFLAGS+=	_GCC_IS_TOO_OLD=${_GCC_IS_TOO_OLD}
.    endif
.    if !empty(_GCC_IS_TOO_OLD:M[yY][eE][sS])
#
# Pre-3.3 GCC has an optimization bug tickled by the db4 code, so remove
# optimization.
#
BUILDLINK_TRANSFORM+=	rm:-O[0-9]*
.    endif
.  endif
.endif

.if defined(WITH_JAVA) && (${WITH_JAVA} == "yes")
CONFIGURE_ARGS+=	--enable-java
.  include "../../mk/java-vm.mk"
.endif

OPSYSVARS+=		LIBSO_LIBS
LIBSO_LIBS.SunOS+=	-lnsl
CONFIGURE_ENV+=		LIBSO_LIBS="${LIBSO_LIBS}"

post-install:
	${CHOWN} -R ${DOCOWN}:${DOCGRP} ${PREFIX}/share/doc/html/db4

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
