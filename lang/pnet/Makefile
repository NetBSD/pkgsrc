# $NetBSD: Makefile,v 1.23 2011/05/21 09:05:26 obache Exp $

DISTNAME=	pnet-0.8.0
#PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://download.savannah.gnu.org/releases/dotgnu-pnet/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dotgnu.org/
COMMENT=	DotGNU Portable.NET (development tools)
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	treecc>=0.2.6:../../devel/treecc

CONFLICTS=	mono-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

# Unsupported by internal libffi
NOT_FOR_PLATFORM=	NetBSD-*-x86_64

MAKE_JOBS_SAFE=	no

USE_TOOLS+=	gmake lex makeinfo
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
INFO_FILES=	# PLIST

PTHREAD_OPTS+=	require native

CONFIGURE_ARGS+=	--enable-threads=posix

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
