# $NetBSD: Makefile,v 1.24 2013/04/07 20:40:38 asau Exp $

DISTNAME=	fossil-src-20120808112557
PKGNAME=	fossil-1.23
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	http://www.fossil-scm.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fossil-scm.org/
COMMENT=	Simple, high-reliability, distributed software configuration management
LICENSE=	2-clause-bsd

MAKE_JOBS_SAFE=	no
HAS_CONFIGURE=	yes

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fossil ${DESTDIR}${PREFIX}/bin

.include "../../devel/readline/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
