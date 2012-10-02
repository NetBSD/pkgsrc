# $NetBSD: Makefile,v 1.27 2012/10/02 20:11:49 asau Exp $

DISTNAME=	pnet-0.8.0
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://download.savannah.gnu.org/releases/dotgnu-pnet/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dotgnu.org/
COMMENT=	DotGNU Portable.NET (development tools)

BUILD_DEPENDS+=	treecc>=0.2.6:../../devel/treecc

CONFLICTS=	mono-[0-9]*
CONFLICTS+=	libffi-[0-9]*
CONFLICTS+=	boehm-gc-[0-9]*

# Unsupported by internal libffi
NOT_FOR_PLATFORM=	NetBSD-*-x86_64
NOT_FOR_PLATFORM+=	DragonFly-*-*

MAKE_JOBS_SAFE=	no

USE_TOOLS+=	gmake lex makeinfo
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
INFO_FILES=	# PLIST

PTHREAD_OPTS+=	require native

CONFIGURE_ARGS+=	--enable-threads=posix

.include "../../mk/termcap.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
