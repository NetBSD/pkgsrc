# $NetBSD: Makefile,v 1.18 2008/06/12 02:14:21 joerg Exp $
#

DISTNAME=	chmlib-0.39
CATEGORIES=	devel
MASTER_SITES=	http://morte.jedrea.com/~jedwin/projects/chmlib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://morte.jedrea.com/~jedwin/projects/chmlib/
COMMENT=	Library for dealing with Microsoft ITSS/CHM format files

CONFLICTS=	kchm-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--disable-io64

INSTALLATION_DIRS=	include lib

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--disable-pthread
.endif

.include "../../mk/bsd.pkg.mk"
