# $NetBSD: Makefile,v 1.24 2008/11/08 13:47:11 bjs Exp $

DISTNAME=	mhash-0.9.9
PKGREVISION=	2
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mhash/}
EXTRACT_SUFX=	.tar.bz2

PATCHFILES+=	mhash-freebsd-patches-20081108.diff.gz
PATCH_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mhash.sourceforge.net/
COMMENT=	Hash algorithms library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake perl autoconf
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	include/mutils

pre-configure:
	cd ${WRKSRC} && autoconf -v -f

.include "../../mk/bsd.pkg.mk"
