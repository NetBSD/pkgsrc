# $NetBSD: Makefile,v 1.2 2005/01/28 14:08:02 taca Exp $

DISTNAME=		ossl-0.1.4a
PKGNAME=		${RUBY_PKGPREFIX}-openssl-0.1.4a
CATEGORIES=		security ruby
MASTER_SITES=		http://freesoftware.fsf.org/download/rubypki/

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		http://www.freesoftware.fsf.org/rubypki/
COMMENT=		OpenSSL interface module for Ruby

CONFLICTS=		ruby-ossl-*

RUBY_HAS_ARCHLIB=	yes
RUBY_VERSION=		${RUBY16_VERSION}
USE_BUILDLINK3=		YES
USE_RUBY_EXTCONF=	YES
WRKSRC=			${WRKDIR}/ossl
CONFIGURE_ARGS=		--with-ssl-include="${BUILDLINK_PREFIX.openssl}/include" \
			--with-ssl-lib="${BUILDLINK_PREFIX.openssl}/lib"
INSTALL_TARGET=		site-install
DOCS=			ChangeLog README

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/openssl
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${RUBY_DOCDIR}/openssl
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
