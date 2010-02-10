# $NetBSD: Makefile,v 1.23 2010/02/10 19:34:06 joerg Exp $

DISTNAME=	vapor-0.81
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	databases ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/215/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vapor.rubyforge.org/
COMMENT=	Ruby transparent persistence to postgresql

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-dbd-pg>=0.0.20:../../databases/ruby-dbd-pg

USE_TOOLS=	pax
USE_RUBY_SETUP= yes
RUBY_SETUP=	install.rb
REPLACE_RUBY=	doc/examples/university/createperson \
		doc/examples/university/createuni \
		doc/examples/university/employment \
		doc/examples/university/enroll

CONFIGURE_ARGS+=	--site-ruby-common=${PREFIX}/${RUBY_VENDORLIB_BASE} \
			--site-ruby=${PREFIX}/${RUBY_VENDORLIB} \
			--so-dir==${PREFIX}/${RUBY_VENDORARCHLIB}


INSTALLATION_DIRS=	${RUBY_DOC}/vapor ${RUBY_EG}

post-install:
	cd ${WRKSRC}/doc; ${PAX} -rw . ${DESTDIR}${PREFIX}/${RUBY_DOC}/vapor
	${LN} -s ${DESTDIR}${PREFIX}/${RUBY_DOC}/vapor ${DESTDIR}${PREFIX}/${RUBY_EG}/vapor

.include "../../lang/ruby/modules.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
