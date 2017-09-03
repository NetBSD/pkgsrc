# $NetBSD: Makefile,v 1.7 2017/09/03 08:53:07 wiz Exp $

DISTNAME=	man-pages-4.05
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.kernel.org/pub/linux/docs/man-pages/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kernel.org/doc/man-pages/
COMMENT=	The Linux man-pages project for Linux kernel and C library interface
#LICENSE=	many, and not even upstream cares about sorting them out

NO_BUILD=	# This package only installs files.

USE_LANGUAGES=	# none
MAKE_FLAGS+=	prefix=${PREFIX} DESTDIR=${DESTDIR}

.include "../../mk/bsd.pkg.mk"
