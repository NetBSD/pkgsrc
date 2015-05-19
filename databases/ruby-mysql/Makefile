# $NetBSD: Makefile,v 1.38 2015/05/19 13:32:38 ryoon Exp $
#

DISTNAME=	ruby-mysql-2.9.13
PKGNAME=	${RUBY_PKGPREFIX}-mysql-2.9.13
CATEGORIES=	databases ruby
MASTER_SITES=	${MASTER_SITE_GITHUB:=tmtm/}
GITHUB_PROJECT=	ruby-mysql
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	neumann@s-direktnet.de
HOMEPAGE=	http://www.tmtm.org/en/mysql/ruby/
COMMENT=	Ruby extension for MySQL
LICENSE=	gnu-gpl-v2 OR ruby-license

USE_RUBY_SETUP=		yes
USE_RUBY_SETUP_PKG=	yes

INSTALLATION_DIRS=	${RUBY_DOC}/mysql ${RUBY_EG}/mysql

DOCS=		README.rdoc

ppost-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/mysql
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/test.rb ${DESTDIR}${PREFIX}/${RUBY_EG}/mysql

.include "../../lang/ruby/modules.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
