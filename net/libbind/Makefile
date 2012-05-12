# $NetBSD: Makefile,v 1.4 2012/05/12 07:37:51 wiz Exp $
#

DISTNAME=	libbind-6.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/libbind/6.0/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://www.isc.org/software/libbind
COMMENT=	ISC Standard Resolver Library
LICENSE=	isc

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		man-pages-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-libtool=yes

MAKE_JOBS_SAFE=	no

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
