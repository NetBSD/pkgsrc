# $NetBSD: Makefile,v 1.21 2006/03/04 21:29:05 jlam Exp $
#

DISTNAME=	gsmlib-1.10
PKGREVISION=	2
CATEGORIES=	comms devel
MASTER_SITES=	http://www.pxh.de/fs/gsmlib/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pxh.de/fs/gsmlib/
COMMENT=	Library to access GSM mobile phones through GSM modems or IrDA devices

BUILD_USES_MSGFMT=	yes

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-included-gettext
PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
