# $NetBSD: Makefile,v 1.10 2015/08/17 17:11:25 wiz Exp $
#

DISTNAME=	dvorakng-0.6.0rc1
PKGREVISION=	2
WRKSRC=		${WRKDIR}/dvorakng
CATEGORIES=	misc
MASTER_SITES=	http://www.free.of.pl/n/nopik/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	US English Dvorak keyboard tutor

USE_NCURSES=		# strange keyboard handling

INSTALLATION_DIRS=	bin

USE_LANGUAGES=	c++

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dvorakng ${DESTDIR}${PREFIX}/bin

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
