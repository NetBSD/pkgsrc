# $NetBSD: Makefile,v 1.8 2004/06/09 16:49:00 minskim Exp $
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

CONFIGURE_ENV+=		ac_cv_lib_curl_curl_formparse=yes

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
