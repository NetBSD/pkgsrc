# $NetBSD: Makefile,v 1.2 2002/02/12 14:57:58 martti Exp $

DISTNAME=	libexif-0.4
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
