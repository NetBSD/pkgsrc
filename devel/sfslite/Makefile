# $NetBSD: Makefile,v 1.7 2020/05/10 14:54:48 rillig Exp $

DISTNAME=	sfslite-1.2.7
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_FREEBSD}

MAINTAINER=	agc@NetBSD.org
#HOMEPAGE=	http://dist.okws.org/sfslite
COMMENT=	Standard version of the sfslite library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-sfsmisc
USE_TOOLS+=		gmake bison
TOOLS_BROKEN+=		perl
USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes
BUILDLINK_TRANSFORM+=	rm:-Werror

AUTO_MKDIRS=	yes

.include "../../devel/gmp/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
