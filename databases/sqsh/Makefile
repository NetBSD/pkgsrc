# $NetBSD: Makefile,v 1.20 2004/03/29 01:52:11 grant Exp $

DISTNAME=	sqsh-1.7-src
PKGNAME=	sqsh-1.7
PKGREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.sqsh.org/
COMMENT=	Sybase SQL shell

ALL_TARGET=		sqsh
INSTALL_TARGET=		install install.man

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-readline

# support for the native Sybase Open Client
BUILD_DEFS+=		USE_SYBASE_OPENCLIENT
BUILD_DEFS+=		SYBASE
.if defined(USE_SYBASE_OPENCLIENT) && empty(USE_SYBASE_OPENCLIENT:M[Nn][Oo])
.  if defined(SYBASE) && exists(${SYBASE}/lib/libct.so)
BUILDLINK_PASSTHRU_DIRS=${SYBASE}
_SYBASE=		${SYBASE}
.  else
PKG_FAIL_REASON+=	"You must define SYBASE to the base directory of Open Client."
.  endif
.else
_SYBASE=		${BUILDLINK_PREFIX.freetds}/freetds
MAKE_FLAGS+=		SYBASE_LIBS=-lct
.endif

LDFLAGS+=		-Wl,${RPATH_FLAG}${_SYBASE}/lib

CONFIGURE_ENV+=		SYBASE="${_SYBASE}"
CONFIGURE_ENV+=		INCDIRS="${BUILDLINK_PREFIX.readline}/include"
CONFIGURE_ENV+=		LIBDIRS="${BUILDLINK_PREFIX.readline}/lib"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sqsh ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/sqsh.1 ${PREFIX}/man/man1/sqsh.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/sqsh
	${INSTALL_DATA} ${WRKSRC}/doc/sample.sqshrc ${PREFIX}/share/examples/sqsh

.if !defined(USE_SYBASE_OPENCLIENT)
.  include "../../databases/freetds/buildlink2.mk"
.endif

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
