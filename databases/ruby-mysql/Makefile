# $NetBSD: Makefile,v 1.15 2005/06/12 15:23:03 taca Exp $
#

DISTNAME=	mysql-ruby-2.6
PKGNAME=	${RUBY_PKGPREFIX}-mysql-2.6
CATEGORIES=	databases ruby
MASTER_SITES=	http://www.tmtm.org/mysql/ruby/

MAINTAINER=	neumann@s-direktnet.de
HOMEPAGE=       http://www.tmtm.org/en/mysql/ruby/
COMMENT=	Ruby extension for MySQL

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
INSTALL_TARGET=		site-install
CONFIGURE_ARGS+= --with-mysql-include-dir=${BUILDLINK_PREFIX.mysql-client}/include \
		--with-mysql-lib-dir=${BUILDLINK_PREFIX.mysql-client}/lib/mysql

DOCS=		README.html README_ja.html tommy.css

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/mysql
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/mysql
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/mysql
	${INSTALL_SCRIPT} ${WRKSRC}/test.rb ${RUBY_EXAMPLESDIR}/mysql

.include "../../lang/ruby/modules.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
