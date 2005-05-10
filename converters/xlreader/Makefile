# $NetBSD: Makefile,v 1.4 2005/05/10 05:53:48 cjs Exp $
#

DISTNAME=	xlreader-0.9.0
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xlreader/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.giffin.org/xlreader.php
COMMENT=	Converts the cells in a MS Excel file to text

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xlreader ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
