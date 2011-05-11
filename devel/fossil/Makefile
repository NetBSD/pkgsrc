# $NetBSD: Makefile,v 1.13 2011/05/11 14:15:28 joerg Exp $
#

DISTNAME=	fossil-src-20110413120518
PKGNAME=	${DISTNAME:S/-src//:C/-(2........)/-\1./}
CATEGORIES=	devel scm
MASTER_SITES=	http://www.fossil-scm.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fossil-scm.org/index.html/doc/tip/www/index.wiki
COMMENT=	Simple, high-reliability, distributed software configuration management
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=	no

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fossil ${DESTDIR}${PREFIX}/bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
