# $NetBSD: Makefile,v 1.11 2012/10/23 18:16:35 asau Exp $
#
# This package currently exists as a dependency for the hydra package but
# the later versions of it are not supported by hydra.
# This package should not be updated to the latest version available.
#

DISTNAME=	libssh-0.11
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://www.0xbadc0de.be/libssh/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0xbadc0de.be/
COMMENT=	Library providing working SSH implementation

GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	share/doc/libssh
INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 \
			prefix=${DESTDIR}${PREFIX}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/API.html ${DESTDIR}${PREFIX}/share/doc/libssh
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/libssh

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
