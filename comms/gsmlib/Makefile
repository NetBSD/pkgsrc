# $NetBSD: Makefile,v 1.9 2003/07/17 21:26:43 grant Exp $
#

DISTNAME=	gsmlib-1.9
PKGREVISION=	3
CATEGORIES=	comms devel
MASTER_SITES=	http://www.pxh.de/fs/gsmlib/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.pxh.de/fs/gsmlib/
COMMENT=	Library to access GSM mobile phones through GSM modems or IrDA devices

BUILD_USES_MSGFMT=	yes

ONLY_FOR_PLATFORM=	NetBSD-1.[6-9]*

USE_GMAKE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-included-gettext
PTHREAD_OPTS+=		require

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
