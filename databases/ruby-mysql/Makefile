# $NetBSD: Makefile,v 1.4 2003/07/13 13:50:59 wiz Exp $
#

DISTNAME=	mysql-ruby-2.4.2
PKGNAME=	${RUBY_PKGNAMEPREFIX}mysql-2.4
PKGREVISION=	2
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
