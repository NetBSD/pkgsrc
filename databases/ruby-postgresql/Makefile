# $NetBSD: Makefile,v 1.4 2001/07/31 00:09:44 taca Exp $

DISTNAME=	ruby-postgres-0.6.4
PKGNAME=	${RUBY_PKGNAMEPREFIX}postgresql-0.6.4
CATEGORIES=	databases
MASTER_SITES=	http://www.jp.postgresql.org/interfaces/ruby/archive/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.jp.postgresql.org/interfaces/ruby/
COMMENT=	Ruby extension for postgresql

DEPENDS+=	postgresql-lib>=7.1:../../databases/postgresql-lib

DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF= yes
CONFIGURE_ARGS+=--with-pgsql-include-dir=${PREFIX}/include/pgsql \
		--with-pgsql-lib-dir=${PREFIX}/lib
INSTALL_TARGET=	site-install

DOC=		README doc/postgres.html
DOC_JA=		README.jp doc/postgres.jp.html
EXAMPLE_LIBS=	losample.rb psqlHelp.rb
EXAMPLE_SCRIPTS=psql.rb test1.rb test2.rb test4.rb
REPLACE_RUBY=	sample/psql.rb sample/test1.rb sample/test2.rb sample/test4.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/postgresql/ja
.for f in ${DOC}
	${INSTALL_DATA} ${WRKSRC}/$f ${RUBY_DOCDIR}/postgresql
.endfor
.for f in ${DOC_JA}
	${INSTALL_DATA} ${WRKSRC}/$f ${RUBY_DOCDIR}/postgresql/ja
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/postgresql
.for f in ${EXAMPLE_LIBS}
	${INSTALL_DATA} ${WRKSRC}/sample/$f ${RUBY_EXAMPLESDIR}/postgresql
.endfor
.for f in ${EXAMPLE_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/sample/$f ${RUBY_EXAMPLESDIR}/postgresql
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
