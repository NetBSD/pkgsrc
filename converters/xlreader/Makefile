# $NetBSD: Makefile,v 1.1.1.1 2003/04/14 17:33:16 zuntum Exp $
#

DISTNAME=	xlreader-0.9.0
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xlreader/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.giffin.org/xlreader.php
COMMENT=	Converts the cells in a MS Excel file to text

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xlreader ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
