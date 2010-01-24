# $NetBSD: Makefile,v 1.3 2010/01/24 13:32:09 wiz Exp $
#

DISTNAME=	fossil-src-20100121205359
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	devel scm
MASTER_SITES=	http://www.fossil-scm.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fossil-scm.org/index.html/doc/tip/www/index.wiki
COMMENT=	Simple, high-reliability, distributed software configuration management
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fossil ${DESTDIR}${PREFIX}/bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
