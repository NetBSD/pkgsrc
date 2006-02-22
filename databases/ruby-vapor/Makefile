# $NetBSD: Makefile,v 1.15 2006/02/22 21:02:47 wiz Exp $

DISTNAME=	vapor-0.81
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	databases ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/215/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://vapor.rubyforge.org/
COMMENT=	Ruby transparent persistence to postgresql

DEPENDS+=	${RUBY_PKGPREFIX}-DBD-postgresql>=0.0.20:../../databases/ruby-DBD-postgresql

USE_RUBY_SETUP= yes
RUBY_SETUP= 	install.rb
REPLACE_RUBY=	doc/examples/university/createperson \
		doc/examples/university/createuni \
		doc/examples/university/employment \
		doc/examples/university/enroll

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/vapor
	${CP} -r ${WRKSRC}/doc/* ${RUBY_DOCDIR}/vapor
	${LN} -s ${RUBY_DOCDIR}/vapor/examples ${RUBY_EXAMPLESDIR}/vapor

.include "../../lang/ruby/modules.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
