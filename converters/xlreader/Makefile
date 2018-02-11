# $NetBSD: Makefile,v 1.9 2018/02/11 15:55:25 wiz Exp $

DISTNAME=	xlreader-0.9.0
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xlreader/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/xlreader/
COMMENT=	Converts the cells in a MS Excel file to text

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xlreader ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
