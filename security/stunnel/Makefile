# $NetBSD: Makefile,v 1.7 2000/12/19 07:03:21 jlam Exp $
#

DISTNAME=		stunnel-3.9
CATEGORIES=		security
MASTER_SITES=		http://www.stunnel.org/download/stunnel/src/

MAINTAINER=		martin@NetBSD.ORG
HOMEPAGE=		http://www.stunnel.org/

BUILD_DEPENDS+=		autoconf:../../devel/autoconf
DEPENDS+=		pth>=1.3.5:../../devel/pth

USE_SSL=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-cert-dir="${SSL_CERT_DIR}"

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../mk/bsd.pkg.mk"

# The in-tree OpenSSL uses /etc/openssl/certs as the default location for
# certificates, while the pkgsrc OpenSSL uses ${PREFIX}/certs.  Define
# SSL_CERT_DIR appropriately using a shell expression, and make sure that
# it's only executed once to optimize the build.
#
.if !defined(SSL_CERT_DIR)
SSL_CERT_DIR!=		if ${TEST} -d /etc/openssl/certs; then	\
				${ECHO} /etc/openssl/certs;	\
			else					\
				${ECHO} ${PREFIX}/certs;	\
			fi
MAKEFLAGS+=		SSL_CERT_DIR="${SSL_CERT_DIR}"
.endif
