# $NetBSD: Makefile,v 1.5 2003/09/11 15:34:02 taca Exp $
#

DISTNAME=	mysql-ruby-2.4.5
PKGNAME=	${RUBY_PKGNAMEPREFIX}mysql-2.4.5
CATEGORIES=	databases
MASTER_SITES=	http://www.tmtm.org/mysql/ruby/

MAINTAINER=	neumann@s-direktnet.de
HOMEPAGE=       http://www.tmtm.org/mysql/ruby/
COMMENT=	Ruby extension for MySQL

USE_BUILDLINK2=	yes

DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF= yes
CONFIGURE_ARGS+= --with-mysql-include-dir=${BUILDLINK_PREFIX.mysql-client}/include \
		--with-mysql-lib-dir=${BUILDLINK_PREFIX.mysql-client}/lib/mysql
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
.include "../../lang/ruby-base/buildlink2.mk"
.include "../../databases/mysql-client/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
