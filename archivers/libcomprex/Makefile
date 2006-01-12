# $NetBSD: Makefile,v 1.17 2006/01/12 13:25:14 joerg Exp $

DISTNAME=	libcomprex-0.3.3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnupdate/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnupdate.org/components/libcomprex/index.xml
COMMENT=	Library to handle (de)compression of files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE=	libcomprex.pc.in
GNU_CONFIGURE=		yes
BROKEN_GETTEXT_DETECTION=	yes
CONFIGURE_ENV+=		ac_cv_lib_curl_curl_formparse=yes

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
