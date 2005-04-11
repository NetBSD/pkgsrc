# $NetBSD: Makefile,v 1.3 2005/04/11 21:46:34 tv Exp $
#

DISTNAME=	dvorakng-0.6.0rc1
PKGREVISION=	1
WRKSRC=		${WRKDIR}/dvorakng
CATEGORIES=	misc
MASTER_SITES=	http://www.free.of.pl/n/nopik/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT= 	US English Dvorak keyboard tutor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_NCURSES=		# strange keyboard handling

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dvorakng ${PREFIX}/bin

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
