# $NetBSD: Makefile,v 1.23 2013/04/06 03:45:09 rodent Exp $

DISTNAME=	fossil-src-20120808112557
PKGNAME=	fossil-1.23
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	http://www.fossil-scm.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fossil-scm.org/
COMMENT=	Simple, high-reliability, distributed software config management
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
