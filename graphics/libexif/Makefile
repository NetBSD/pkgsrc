# $NetBSD: Makefile,v 1.3 2002/02/25 09:01:41 martti Exp $

DISTNAME=	libexif-0.5.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libexif/}

MAINTAINER=	packages@@netbsd.org
HOMEPAGE=	http://libexif.sourceforge.net/
COMMENT=	EXIF file library

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
