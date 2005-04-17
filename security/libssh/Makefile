# $NetBSD: Makefile,v 1.1.1.1 2005/04/17 11:34:16 adrianp Exp $
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
