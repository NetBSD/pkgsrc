# $NetBSD: Makefile,v 1.11 2003/11/02 17:42:26 taca Exp $

DISTNAME=		ruby-postgres-${VERSION}
PKGNAME=		${RUBY_PKGNAMEPREFIX}postgresql-${VERSION}
CATEGORIES=		databases
MASTER_SITES=		http://www.postgresql.jp/interfaces/ruby/archive/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.postgresql.jp/interfaces/ruby/
COMMENT=		Ruby extension for postgresql

USE_BUILDLINK2=		# defined

VERSION=		0.7.1
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

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../lang/ruby-base/Makefile.common"
.include "../../lang/ruby-base/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
