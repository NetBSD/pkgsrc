# $NetBSD: Makefile,v 1.5 2002/08/25 19:21:47 jlam Exp $
#

DISTNAME=	id3lib-3.8.0pre2
PKGNAME=	id3lib-3.8.0.0.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=id3lib/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://id3lib.sourceforge.net/
COMMENT=	library for manipulating ID3v1 and ID3v2 tags

GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-extract:
	${MV} ${WRKSRC}/include/id3/strings.h \
		${WRKSRC}/include/id3/id3strings.h

.include "../../mk/bsd.pkg.mk"
