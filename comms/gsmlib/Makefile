# $NetBSD: Makefile,v 1.14 2004/10/03 00:13:16 tv Exp $
#

DISTNAME=	gsmlib-1.10
PKGREVISION=	1
CATEGORIES=	comms devel
MASTER_SITES=	http://www.pxh.de/fs/gsmlib/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.pxh.de/fs/gsmlib/
COMMENT=	Library to access GSM mobile phones through GSM modems or IrDA devices

BUILD_USES_MSGFMT=	yes

USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-included-gettext
PTHREAD_OPTS+=		require
CFLAGS+=		${PTHREAD_CFLAGS}
LDFLAGS+=		${PTHREAD_LDFLAGS}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
