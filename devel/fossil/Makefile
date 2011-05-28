# $NetBSD: Makefile,v 1.14 2011/05/28 10:33:00 asau Exp $
#

DISTNAME=	fossil-src-20110523151112
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
