# $NetBSD: Makefile,v 1.8 2022/09/24 06:48:55 wiz Exp $

DISTNAME=	libbind-6.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/libbind/6.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.isc.org/software/libbind
COMMENT=	ISC Standard Resolver Library
LICENSE=	isc

CONFLICTS=		man-pages-[0-9]*

NOT_FOR_PLATFORM=	NetBSD-*-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.prefs.mk"

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS]) && ${OPSYS} == "NetBSD"
# Yes, we'll have /dev/random on NetBSD, even autoconf you can't detect
# it by compiling and running a program when cross-compiling.
CONFIGURE_ENV+=		ac_cv_file__dev_random=yes
.endif

CONFIGURE_ARGS+=	--with-libtool=yes

MAKE_JOBS_SAFE=	no

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
