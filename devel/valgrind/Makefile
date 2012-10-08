# $NetBSD: Makefile,v 1.9 2012/10/08 19:42:47 alnsn Exp $
#

DISTNAME=		valgrind-3.8.1
CATEGORIES=		devel
MASTER_SITES=		http://valgrind.org/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		alnsn@NetBSD.org
HOMEPAGE=		http://valgrind.org/downloads/
COMMENT=		Debugging and profiling tools
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/valgrind.pc.in
GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	Linux-*-*

USE_TOOLS+=		gmake perl
USE_LANGUAGES=		c c++
TEST_TARGET=		regtest

.include "../../mk/bsd.pkg.mk"
