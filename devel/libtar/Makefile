# $NetBSD: Makefile,v 1.17 2019/06/22 11:31:06 nia Exp $
#

DISTNAME=	libtar-1.2.20
CATEGORIES=	devel archivers
MASTER_SITES=	http://pkgbuild.com/~giovanni/libtar/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://repo.or.cz/w/libtar.git/
COMMENT=	Library for manipulating POSIX tar files

WRKSRC=			${WRKDIR}/libtar
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake autoreconf gmake

pre-configure:
	cd ${WRKSRC} && autoreconf -fvi

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
