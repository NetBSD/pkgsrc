# $NetBSD: Makefile,v 1.2 2001/07/16 14:40:37 taca Exp $
# FreeBSD: ports/security/ruby-ssl/Makefile,v 1.2 2001/01/11 20:39:53 knu Exp

DISTNAME=	ssl-0.3.1
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://www.notwork.org/~gotoyuzo/ruby/src/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	# not available
COMMENT=	SSL socket module for Ruby

DIST_SUBDIR=	ruby
USE_SSL=	yes
USE_RUBY_EXTCONF= yes
RUBY_REQD=	1.6.4		# need forwardable module

CONFIGURE_ARGS=	--with-ssl-include="${SSLBASE}/include/openssl" \
		--with-ssl-lib="${SSLBASE}/lib"
INSTALL_TARGET=	site-install

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/ssl
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/ssl

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
