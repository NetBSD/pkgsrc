# $NetBSD: Makefile,v 1.8 2003/07/17 21:29:01 grant Exp $

DISTNAME=		ruby-postgres-${VERSION}
PKGNAME=		${RUBY_PKGNAMEPREFIX}postgresql-${VERSION}
PKGREVISION=		1
CATEGORIES=		databases
MASTER_SITES=		http://www.postgresql.jp/interfaces/ruby/archive/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.postgresql.jp/interfaces/ruby/
COMMENT=		Ruby extension for postgresql

DEPENDS+=		postgresql-lib>=7.3.1:../../databases/postgresql-lib

VERSION=		0.6.5
DIST_SUBDIR=		ruby
USE_RUBY_EXTCONF= 	yes
CONFIGURE_ARGS+=	--with-pgsql-include-dir=${PREFIX}/include/postgresql \
			--with-pgsql-lib-dir=${PREFIX}/lib
INSTALL_TARGET=		site-install

DOC=			README README.ja doc/postgres.html doc/postgres.ja.html
EXAMPLE_LIBS=		losample.rb psqlHelp.rb
EXAMPLE_SCRIPTS=	psql.rb test1.rb test2.rb test4.rb
REPLACE_RUBY=		sample/psql.rb sample/test1.rb sample/test2.rb \
			sample/test4.rb

pre-install:
	@cd ${WRKSRC}; \
		${CP} -p README.jp README.ja; \
		${CP} -p doc/postgres.jp.html doc/postgres.ja.html

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/postgresql
.for f in ${DOC}
	${INSTALL_DATA} ${WRKSRC}/$f ${RUBY_DOCDIR}/postgresql
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
