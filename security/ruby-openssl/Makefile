# $NetBSD: Makefile,v 1.4 2002/10/25 09:36:24 wiz Exp $

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
USE_BUILDLINK2=		# defined
USE_OPENSSL_VERSION=	${OPENSSL_VERSION_096}

CONFIGURE_ARGS=		--with-ssl-include="${BUILDLINK_PREFIX.openssl}/include" \
			--with-ssl-lib="${BUILDLINK_PREFIX.openssl}/lib"
INSTALL_TARGET=		site-install
DOCS=			ChangeLog README

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/openssl
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${RUBY_DOCDIR}/openssl
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../lang/ruby-base/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
