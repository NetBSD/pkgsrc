# $NetBSD: Makefile,v 1.4 2003/05/02 11:53:45 wiz Exp $
#

DISTNAME=	streamtuner-local-0.2.1
PKGREVISION=	2
CATEGORIES=	audio www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=streamtuner/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.nongnu.org/streamtuner/
COMMENT=	Streamtuner plugin providing access to your local MP3 repository

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11=	YES

SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--with-id3lib="${BUILDLINK_PREFIX.id3lib}"

.include "../../audio/id3lib/buildlink2.mk"
.include "../../audio/streamtuner/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
