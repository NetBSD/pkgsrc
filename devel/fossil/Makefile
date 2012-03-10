# $NetBSD: Makefile,v 1.18 2012/03/10 08:04:45 sbd Exp $

DISTNAME=	Fossil-002580c50d94790a
PKGNAME=	fossil-1.21
PKGREVISION=	1
CATEGORIES=	devel scm
# have to log in to download the tarball
MASTER_SITES=	${MASTER_SITE_LOCAL}

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
