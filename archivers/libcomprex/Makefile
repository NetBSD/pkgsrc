# $NetBSD: Makefile,v 1.5 2004/02/14 17:21:32 jlam Exp $
#

DISTNAME=	libcomprex-0.3.2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnupdate/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnupdate.org/components/libcomprex/index.xml
COMMENT=	Library to handle (de)compression of files

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../www/curl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
