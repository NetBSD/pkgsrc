# $NetBSD: Makefile,v 1.5 2001/05/22 05:28:23 jlam Exp $

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

.include "../../devel/readline/Makefile.readline"

LDFLAGS+=		-L${WRKLIBDIR}
CONFIGURE_ENV+=		INCDIRS="${WRKINCDIR}"
CONFIGURE_ENV+=		LIBDIRS="${WRKLIBDIR}"

pre-configure: link-readline-headers link-readline-libs

.include "../../mk/bsd.pkg.mk"
