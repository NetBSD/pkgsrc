# $NetBSD: Makefile,v 1.7 2004/03/26 02:27:34 wiz Exp $
#

DISTNAME=	libcomprex-0.3.2
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnupdate/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnupdate.org/components/libcomprex/index.xml
COMMENT=	Library to handle (de)compression of files

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
