# $NetBSD: Makefile,v 1.6 2001/05/24 08:53:55 jlam Exp $

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

LDFLAGS+=		-L${BUILDLINK_LIBDIR}
CONFIGURE_ENV+=		INCDIRS="${BUILDLINK_INCDIR}"
CONFIGURE_ENV+=		LIBDIRS="${BUILDLINK_LIBDIR}"

pre-configure: ${BUILDLINK_TARGETS}

.include "../../mk/bsd.pkg.mk"
