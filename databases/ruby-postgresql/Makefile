# $NetBSD: Makefile,v 1.19 2005/01/31 05:00:13 taca Exp $

DISTNAME=		ruby-postgres-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-postgresql-${VERSION}
PKGREVISION=		1
CATEGORIES=		databases ruby
MASTER_SITES=		http://www.postgresql.jp/interfaces/ruby/archive/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.postgresql.jp/interfaces/ruby/
COMMENT=		Ruby extension for postgresql

RUBY_HAS_ARCHLIB=	yes
USE_BUILDLINK3=		yes
USE_RUBY_EXTCONF= 	yes
VERSION=		0.7.1
INSTALL_TARGET=		site-install
CONFIGURE_ARGS+= --with-pgsql-include-dir=${PGSQL_PREFIX}/include/postgresql \
		 --with-pgsql-lib-dir=${PGSQL_PREFIX}/lib

DOC=			README README.ja doc/postgres.html doc/postgres.ja.html
EXAMPLE_LIBS=		losample.rb psqlHelp.rb
EXAMPLE_SCRIPTS=	psql.rb test1.rb test2.rb test4.rb
REPLACE_RUBY=		sample/psql.rb sample/test1.rb sample/test2.rb \
			sample/test4.rb

PGSQL_VERSION_REQD=	73

pre-install:
	@cd ${WRKSRC}; \
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

.include "../../lang/ruby/modules.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
