# $NetBSD: Makefile,v 1.18 2005/01/23 17:36:03 taca Exp $

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-openssl-${RUBY_VERSION}
CATEGORIES=	security ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	OpenSSL interface module for Ruby

RUBY_HAS_ARCHLIB=	yes
RUBY_VERSION_SUPPORTED=	18
USE_BUILDLINK3=		yes
USE_RUBY_EXTCONF=	yes
DISTINFO_FILE=		${RUBY_DISTINFO_FILE}
WRKSRC=			${RUBY_WRKSRC}/ext/openssl
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/openssl \
			${RUBY_DISTNAME}/sample/openssl

CONFIGURE_ARGS=	--with-ssl-include="${BUILDLINK_PREFIX.openssl}/include" \
		--with-ssl-lib="${BUILDLINK_PREFIX.openssl}/lib"
EXAMPLES=	c_rehash.rb cert2text.rb cert_store_view.rb certstore.rb \
		cipher.rb crlstore.rb echo_cli.rb echo_svr.rb gen_csr.rb \
		smime_read.rb smime_write.rb wget.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/openssl
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${RUBY_WRKSRC}/sample/openssl/$f \
		${RUBY_EXAMPLESDIR}/openssl
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
