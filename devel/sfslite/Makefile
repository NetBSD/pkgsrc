# $NetBSD: Makefile,v 1.2 2012/06/18 03:28:55 dholland Exp $

DISTNAME=	sfslite-1.2.7
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_FREEBSD}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://dist.okws.org/sfslite
COMMENT=	Standard version of the sfslite library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-sfsmisc
USE_TOOLS=	gmake bison
USE_LANGUAGES+=	c c++
USE_LIBTOOL=	yes

PKG_DESTDIR_SUPPORT=	user-destdir
AUTO_MKDIRS=	yes

.include "../../devel/gmp/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
