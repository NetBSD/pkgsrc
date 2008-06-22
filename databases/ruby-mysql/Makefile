# $NetBSD: Makefile,v 1.28 2008/06/22 15:51:14 taca Exp $
#

DISTNAME=	mysql-ruby-2.7.6
PKGNAME=	${RUBY_PKGPREFIX}-mysql-2.7.6
CATEGORIES=	databases ruby
MASTER_SITES=	http://tmtm.org/downloads/mysql/ruby/

MAINTAINER=	neumann@s-direktnet.de
HOMEPAGE=	http://www.tmtm.org/en/mysql/ruby/
COMMENT=	Ruby extension for MySQL

RUBY_HAS_ARCHLIB=	yes
RUBY_REQD=		1.8.2
USE_RUBY_EXTCONF=	yes
INSTALL_TARGET=		site-install
CONFIGURE_ARGS+=	--with-mysql-config
INSTALLATION_DIRS=	${RUBY_DOC}/mysql ${RUBY_EG}/mysql

DOCS=		README.html README_ja.html tommy.css

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/mysql
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/test.rb ${DESTDIR}${PREFIX}/${RUBY_EG}/mysql

.include "../../lang/ruby/modules.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
