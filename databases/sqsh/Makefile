# $NetBSD: Makefile,v 1.1.1.1 2000/05/16 01:07:05 tsarna Exp $

DISTNAME=	sqsh-1.7-src
PKGNAME=	sqsh-1.7
CATEGORIES=	databases
MASTER_SITES=	http://www.voicenet.com/~gray/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.voicenet.com/~gray/sqsh.html

DEPENDS+=       freetds-0.50:../../databases/freetds
DEPENDS+=       readline-4.0:../../devel/readline

ALL_TARGET=	sqsh

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ENV+=		INCDIRS="${PREFIX}/include" \
			LIBDIRS="${PREFIX}/lib" \
			SYBASE="${PREFIX}/freetds"

WRKSRC=		${WRKDIR}/${PKGNAME}

.include "../../mk/bsd.pkg.mk"
