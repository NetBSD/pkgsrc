# $NetBSD: Makefile,v 1.6 2003/07/17 22:52:24 grant Exp $

DISTNAME=	bg5ps-1.3.0
CATEGORIES=	print converters
MASTER_SITES=	ftp://ftp.shellhung.org/pub/OpenBSD/packages/chinese/bg5ps/ \
		ftp://freebsd.sinica.edu.tw/pub/keith/

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://students.washington.edu/cschin/bg5ps/
COMMENT=	convert Big5/GB encoded files to postscript

DEPENDS+=	arphic-ttf>=2.11:../../fonts/arphic-ttf

USE_BUILDLINK2=		yes
PKG_SYSCONFSUBDIR?=	bg5ps

post-patch:
	@${SED} 's|%%ETCDIR%%|${PKG_SYSCONFDIR}|g' \
		${WRKSRC}/bg5ps > ${WRKSRC}/bg5ps.new

.include "../../lang/python/extension.mk"
.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
