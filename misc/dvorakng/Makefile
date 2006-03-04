# $NetBSD: Makefile,v 1.4 2006/03/04 21:30:10 jlam Exp $
#

DISTNAME=	dvorakng-0.6.0rc1
PKGREVISION=	1
WRKSRC=		${WRKDIR}/dvorakng
CATEGORIES=	misc
MASTER_SITES=	http://www.free.of.pl/n/nopik/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT= 	US English Dvorak keyboard tutor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_NCURSES=		# strange keyboard handling

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dvorakng ${PREFIX}/bin

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
