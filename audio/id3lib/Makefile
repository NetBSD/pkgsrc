# $NetBSD: Makefile,v 1.2 2001/08/03 17:05:16 wiz Exp $
#

DISTNAME=	id3lib-3.8.0pre1
PKGNAME=	id3lib-3.8.0.0.1
CATEGORIES=	audio
MASTER_SITES=	http://prdownloads.sourceforge.net/id3lib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://id3lib.sourceforge.net/
COMMENT=	library for manipulating ID3v1 and ID3v2 tags

GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
