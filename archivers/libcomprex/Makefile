# $NetBSD: Makefile,v 1.1.1.1 2002/11/18 16:22:13 cjep Exp $
#

DISTNAME=	libcomprex-0.3.2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnupdate/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnupdate.org/components/libcomprex/index.xml
COMMENT=	Library to handle (de)compression of files

USE_BUILDLINK2=         YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=${WRKSRC}/libtool

.include "../../www/curl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
