# $NetBSD: Makefile,v 1.19 2012/03/22 23:12:41 asau Exp $

DISTNAME=	fossil-src-20120317175325
PKGNAME=	fossil-1.22
CATEGORIES=	devel scm
MASTER_SITES=	http://www.fossil-scm.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fossil-scm.org/
COMMENT=	Simple, high-reliability, distributed software configuration management
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=	no
HAS_CONFIGURE=	yes

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fossil ${DESTDIR}${PREFIX}/bin

.include "../../devel/readline/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
