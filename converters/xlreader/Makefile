# $NetBSD: Makefile,v 1.2 2003/06/02 01:21:13 jschauma Exp $
#

DISTNAME=	xlreader-0.9.0
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xlreader/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.giffin.org/xlreader.php
COMMENT=	Converts the cells in a MS Excel file to text

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xlreader ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
