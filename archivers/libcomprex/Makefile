# $NetBSD: Makefile,v 1.27 2012/12/16 01:51:57 obache Exp $

DISTNAME=	libcomprex-0.3.3
PKGREVISION=	6
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnupdate/}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
REPLACE_SH=		comprex-config.in

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
