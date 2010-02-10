# $NetBSD: Makefile,v 1.16 2010/02/10 19:17:44 joerg Exp $

DISTNAME=	bg5ps-1.3.0
PKGREVISION=	3
CATEGORIES=	print converters
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/

MAINTAINER=	pkgsrc-users@NetBSD.org
# HOMEPAGE=	http://students.washington.edu/cschin/bg5ps/
COMMENT=	Convert Big5/GB encoded files to postscript

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	arphic-ttf>=2.11:../../fonts/arphic-ttf

PKG_SYSCONFSUBDIR?=	bg5ps

post-patch:
	@${SED} 's|%%ETCDIR%%|${PKG_SYSCONFDIR}|g' \
		${WRKSRC}/bg5ps > ${WRKSRC}/bg5ps.new

.include "../../lang/python/extension.mk"
.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
