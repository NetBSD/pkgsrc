# $NetBSD: Makefile,v 1.13 2008/03/04 15:39:09 jlam Exp $
#

DISTNAME=	sgif1122
PKGNAME=	giftrans-1.12.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.rz.uni-karlsruhe.de/pub/net/www/tools/giftrans/
COMMENT=	Manipulate GIF89a images' transparency, comment and other data

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/usr/src/${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/giftrans ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/giftrans.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
