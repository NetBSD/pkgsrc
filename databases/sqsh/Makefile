# $NetBSD: Makefile,v 1.18 2004/01/20 12:12:49 agc Exp $

DISTNAME=	sqsh-1.7-src
PKGNAME=	sqsh-1.7
PKGREVISION=	2
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
CONFIGURE_ENV+=		SYBASE="${BUILDLINK_PREFIX.freetds}/${SYBASE}"

SYBASE=			freetds
LDFLAGS+=		-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.freetds}/${SYBASE}/lib

CONFIGURE_ENV+=		INCDIRS="${BUILDLINK_PREFIX.readline}/include"
CONFIGURE_ENV+=		LIBDIRS="${BUILDLINK_PREFIX.readline}/lib"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sqsh ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/sqsh.1 ${PREFIX}/man/man1/sqsh.1

.include "../../databases/freetds/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
