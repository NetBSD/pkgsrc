# $NetBSD: Makefile,v 1.16 2015/12/13 18:26:07 bsiegert Exp $
#

DISTNAME=	libtar-1.2.20
CATEGORIES=	devel archivers
MASTER_SITES=	http://pkgbuild.com/~giovanni/libtar/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://repo.or.cz/w/libtar.git/
COMMENT=	Library for manipulating POSIX tar files

WRKSRC=			${WRKDIR}/libtar
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake autoreconf gmake

pre-configure:
	cd ${WRKSRC} && autoreconf -fvi

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
