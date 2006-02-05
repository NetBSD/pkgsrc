# $NetBSD: Makefile,v 1.12 2006/02/05 23:10:35 joerg Exp $

DISTNAME=	bg5ps-1.3.0
PKGREVISION=	2
CATEGORIES=	print converters
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://students.washington.edu/cschin/bg5ps/
COMMENT=	Convert Big5/GB encoded files to postscript

DEPENDS+=	arphic-ttf>=2.11:../../fonts/arphic-ttf

PKG_SYSCONFSUBDIR?=	bg5ps

post-patch:
	@${SED} 's|%%ETCDIR%%|${PKG_SYSCONFDIR}|g' \
		${WRKSRC}/bg5ps > ${WRKSRC}/bg5ps.new

.include "../../lang/python/extension.mk"
.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
