# $NetBSD: Makefile,v 1.2 2002/03/21 04:48:05 fredb Exp $
#

DISTNAME=	mysql-ruby-2.4.2
PKGNAME=	${RUBY_PKGNAMEPREFIX}mysql-2.4
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.tmtm.org/mysql/ruby/

MAINTAINER=	neumann@s-direktnet.de
HOMEPAGE=       http://www.tmtm.org/mysql/ruby/
COMMENT=	Ruby extension for MySQL

DEPENDS+=	ruby-base>=1.6.7nb1:../../lang/ruby-base

DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF= yes
CONFIGURE_ARGS+= --with-mysql-include-dir=${PREFIX}/include \
		--with-mysql-lib-dir=${PREFIX}/lib/mysql
INSTALL_TARGET=	site-install

DOCS=		README README.ja
TEST_SCRIPTS=   test.rb
TEST_SCRIPTS2=  00connect.rb 10create_db.rb 20create_table.rb 30insert.rb \
		40select.rb 50update.rb 60drop_table.rb 70drop_db.rb \
		80close.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/mysql
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${RUBY_DOCDIR}/mysql
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/mysql/t
.for f in ${TEST_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/$f ${RUBY_EXAMPLESDIR}/mysql
.endfor
.for f in ${TEST_SCRIPTS2}
	${INSTALL_SCRIPT} ${WRKSRC}/t/$f ${RUBY_EXAMPLESDIR}/mysql/t
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../databases/mysql-client/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
