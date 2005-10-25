# $NetBSD: Makefile,v 1.10 2005/10/25 04:15:48 taca Exp $

DISTNAME=	vapor-0.81
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/215/

MAINTAINER=	rasputin@idoru.mine.nu
HOMEPAGE=	http://vapor.rubyforge.org/
COMMENT=	Ruby transparent persistence to postgresql

USE_RUBY_DIST_SUBDIR=	yes

.include "../../lang/ruby/rubyversion.mk"

DEPENDS+=	${RUBY_PKGPREFIX}-DBD-postgresql>=0.0.20:../../databases/ruby-DBD-postgresql
.if ${RUBY_VER} == 16
DEPENDS+=	${RUBY_PKGPREFIX}-rexml>=2.4.0:../../textproc/ruby-rexml
DEPENDS+=	${RUBY_PKGPREFIX}-racc>=1.4.3:../../devel/ruby-racc
.endif

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
