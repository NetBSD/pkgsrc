# $NetBSD: Makefile,v 1.4 2002/10/13 12:25:55 wiz Exp $
#

DISTNAME=	gsmlib-1.9
PKGREVISION=	1
CATEGORIES=	comms devel
MASTER_SITES=	http://www.pxh.de/fs/gsmlib/download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.pxh.de/fs/gsmlib/
COMMENT=	Library to access GSM mobile phones through GSM modems or IrDA devices

ONLY_FOR_PLATFORM=	NetBSD-1.[6-9]*

BUILD_USES_MSGFMT=	yes

USE_GMAKE=		YES
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"
PTHREAD_OPTS+=		require

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
