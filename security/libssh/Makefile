# $NetBSD: Makefile,v 1.5 2006/02/05 00:20:17 adrianp Exp $
#
# This package currently exists as a dependency for the hydra package but
# the later versions of it are not supported by hydra.
# This package should not be updated to the latest version available.
#

DISTNAME=	libssh-0.11
CATEGORIES=	security
MASTER_SITES=	http://www.0xbadc0de.be/libssh/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://0xbadc0de.be/
COMMENT=	Library providing working SSH implementation

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libssh
	${INSTALL_DATA} ${WRKSRC}/doc/API.html ${PREFIX}/share/doc/libssh
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libssh

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
