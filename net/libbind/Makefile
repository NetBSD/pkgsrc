# $NetBSD: Makefile,v 1.2 2010/05/06 13:13:11 obache Exp $
#

DISTNAME=	libbind-6.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/libbind/6.0/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://www.isc.org/software/libbind
COMMENT=	ISC Standard Resolver Library
LICENSE=	isc

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	nroff tbl

CONFIGURE_ARGS+=	--with-libtool=yes

MAKE_JOBS_SAFE=	no

BUILD_TARGET=	all man

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
