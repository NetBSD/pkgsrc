# $NetBSD: Makefile,v 1.15 2004/04/27 05:44:22 snj Exp $

DISTNAME=		ossl-0.1.4a
PKGNAME=		${RUBY_PKGNAMEPREFIX}openssl-0.1.4.1
PKGREVISION=		2
CATEGORIES=		security ruby
MASTER_SITES=		http://freesoftware.fsf.org/download/rubypki/

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		http://www.freesoftware.fsf.org/rubypki/
COMMENT=		OpenSSL interface module for Ruby

WRKSRC=			${WRKDIR}/ossl
DIST_SUBDIR=		ruby
USE_RUBY_EXTCONF=	yes
RUBY_REQD=		1.6.4
USE_BUILDLINK3=		yes
CONFLICTS=		ruby-ossl-*

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
.include "../../lang/ruby-base/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
