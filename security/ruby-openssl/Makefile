# $NetBSD: Makefile,v 1.3 2002/08/30 23:48:22 taca Exp $

DISTNAME=		ossl-0.1.2a
PKGNAME=		${RUBY_PKGNAMEPREFIX}openssl-0.1.2.1
CATEGORIES=		security
MASTER_SITES=		http://freesoftware.fsf.org/download/rubypki/

MAINTAINER=		taca@netbsd.org
HOMEPAGE=		http://www.freesoftware.fsf.org/rubypki/
COMMENT=		OpenSSL interface module for Ruby

DIST_SUBDIR=		ruby
USE_RUBY_EXTCONF=	yes
RUBY_REQD=		1.6.4
USE_BUILDLINK_ONLY=	# defined
USE_OPENSSL_VERSION=	${OPENSSL_VERSION_096}

CONFIGURE_ARGS=		--with-ssl-include="${BUILDLINK_DIR}/include" \
			--with-ssl-lib="${BUILDLINK_DIR}/lib"
INSTALL_TARGET=		site-install
DOCS=			ChangeLog README

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/openssl
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${RUBY_DOCDIR}/openssl
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
