# $NetBSD: Makefile,v 1.9 2004/10/03 00:18:04 tv Exp $

DISTNAME=	bg5ps-1.3.0
PKGREVISION=	1
CATEGORIES=	print converters
MASTER_SITES=	ftp://ftp.shellhung.org/pub/OpenBSD/packages/chinese/bg5ps/ \
		ftp://freebsd.sinica.edu.tw/pub/keith/

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://students.washington.edu/cschin/bg5ps/
COMMENT=	Convert Big5/GB encoded files to postscript

DEPENDS+=	arphic-ttf>=2.11:../../fonts/arphic-ttf

USE_BUILDLINK3=		yes
PKG_SYSCONFSUBDIR?=	bg5ps

post-patch:
	@${SED} 's|%%ETCDIR%%|${PKG_SYSCONFDIR}|g' \
		${WRKSRC}/bg5ps > ${WRKSRC}/bg5ps.new

.include "../../lang/python/extension.mk"
.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
