# $NetBSD: Makefile,v 1.10 2002/03/12 01:52:27 wiz Exp $

DISTNAME=	sqsh-1.7-src
PKGNAME=	sqsh-1.7
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	databases
MASTER_SITES=	http://www.voicenet.com/~gray/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.voicenet.com/~gray/sqsh.html
COMMENT=	Sybase SQL shell

ALL_TARGET=		sqsh
INSTALL_TARGET=		install install.man

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ENV+=		SYBASE="${BUILDLINK_DIR}/${SYBASE}"

SYBASE=			freetds
LDFLAGS+=		-Wl,-R${LOCALBASE}/${SYBASE}/lib

CONFIGURE_ENV+=		INCDIRS="${BUILDLINK_DIR}/include"
CONFIGURE_ENV+=		LIBDIRS="${BUILDLINK_DIR}/lib"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sqsh ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/sqsh.1 ${PREFIX}/man/man1/sqsh.1

.include "../../databases/freetds/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
