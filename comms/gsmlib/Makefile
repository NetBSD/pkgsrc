# $NetBSD: Makefile,v 1.1.1.1 2002/06/17 11:29:58 grant Exp $
#

DISTNAME=	gsmlib-1.9
CATEGORIES=	comms devel
MASTER_SITES=	http://www.pxh.de/fs/gsmlib/download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.pxh.de/fs/gsmlib/
COMMENT=	Library to access GSM mobile phones through GSM modems or IrDA devices

ONLY_FOR_PLATFORM=	NetBSD-1.[6-9]*

BUILD_USES_MSGFMT=	yes

USE_GMAKE=		YES
USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/pth/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
