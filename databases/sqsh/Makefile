# $NetBSD: Makefile,v 1.8 2001/06/11 02:05:09 jlam Exp $

DISTNAME=	sqsh-1.7-src
PKGNAME=	sqsh-1.7
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	databases
MASTER_SITES=	http://www.voicenet.com/~gray/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.voicenet.com/~gray/sqsh.html
COMMENT=	Sybase SQL shell

DEPENDS+=       freetds>=0.50:../../databases/freetds

ALL_TARGET=	sqsh
INSTALL_TARGET=	install install.man

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ENV+=		SYBASE="${SYBASE}"

SYBASE=			${PREFIX}/freetds
LDFLAGS+=		-Wl,-R${SYBASE}/lib

.include "../../devel/readline/buildlink.mk"

CONFIGURE_ENV+=		INCDIRS="${BUILDLINK_DIR}/include"
CONFIGURE_ENV+=		LIBDIRS="${BUILDLINK_DIR}/lib"

.include "../../mk/bsd.pkg.mk"
