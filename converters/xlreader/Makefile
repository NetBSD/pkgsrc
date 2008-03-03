# $NetBSD: Makefile,v 1.7 2008/03/03 05:51:08 jlam Exp $
#

DISTNAME=	xlreader-0.9.0
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xlreader/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.giffin.org/xlreader.php
COMMENT=	Converts the cells in a MS Excel file to text

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xlreader ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
