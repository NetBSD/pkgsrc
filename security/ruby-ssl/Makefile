# $NetBSD: Makefile,v 1.5 2001/07/26 04:44:10 jlam Exp $
# FreeBSD: ports/security/ruby-ssl/Makefile,v 1.2 2001/01/11 20:39:53 knu Exp

DISTNAME=	ssl-0.3.1c
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://www.notwork.org/~gotoyuzo/ruby/src/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	# not available
COMMENT=	SSL socket module for Ruby

DIST_SUBDIR=		ruby
USE_SSL=		yes
USE_RUBY_EXTCONF=	yes
RUBY_REQD=		1.6.4	# need forwardable module
USE_BUILDLINK_ONLY=	# defined
USE_OPENSSL_VERSION=	${OPENSSL_VERSION_096}

CONFIGURE_ARGS=	--with-ssl-include="${BUILDLINK_DIR}/include" \
		--with-ssl-lib="${BUILDLINK_DIR}/lib"
INSTALL_TARGET=	site-install
DOCS=		ChangeLog README

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/ssl
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${RUBY_DOCDIR}/ssl
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/ssl
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/ssl

.include "../../lang/ruby-base/Makefile.common"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
