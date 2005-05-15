# $NetBSD: Makefile,v 1.2 2005/05/15 17:11:04 adrianp Exp $
#
# This package currently exists as a dependency for the hydra package but 
# the later versions of it are not supported by hydra.
# This package should not be updated to the latest version available.
#

DISTNAME=	libssh-0.1
CATEGORIES=	security
MASTER_SITES=	http://www.0xbadc0de.be/libssh/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://0xbadc0de.be/
COMMENT=	Working SSH implementation by the mean of a library

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libssh
	${INSTALL_DATA} ${WRKSRC}/API.txt ${PREFIX}/share/doc/libssh
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libssh

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
