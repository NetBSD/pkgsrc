# $NetBSD: Makefile,v 1.11 2003/06/02 01:19:23 jschauma Exp $

DISTNAME=	libexif-0.5.9
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libexif/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://libexif.sourceforge.net/
COMMENT=	EXIF file library

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
