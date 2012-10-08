# $NetBSD: Makefile,v 1.8 2012/10/08 09:57:20 asau Exp $
#

DISTNAME=	dvorakng-0.6.0rc1
PKGREVISION=	1
WRKSRC=		${WRKDIR}/dvorakng
CATEGORIES=	misc
MASTER_SITES=	http://www.free.of.pl/n/nopik/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	US English Dvorak keyboard tutor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_NCURSES=		# strange keyboard handling

INSTALLATION_DIRS=	bin

USE_LANGUAGES=	c++

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dvorakng ${DESTDIR}${PREFIX}/bin

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
