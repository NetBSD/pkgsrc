# $NetBSD: Makefile,v 1.10 2004/08/11 16:31:49 ben Exp $
#

DISTNAME=	libcomprex-0.3.2
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnupdate/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnupdate.org/components/libcomprex/index.xml
COMMENT=	Library to handle (de)compression of files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

CONFIGURE_ENV+=		ac_cv_lib_curl_curl_formparse=yes

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
