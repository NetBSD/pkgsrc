# $NetBSD: Makefile,v 1.6 2002/08/31 01:56:56 wiz Exp $
#

DISTNAME=	id3lib-3.8.0
PKGNAME=	id3lib-3.8.0.0.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=id3lib/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://id3lib.sourceforge.net/
COMMENT=	library for manipulating ID3v1 and ID3v2 tags

GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
