# $NetBSD: Makefile,v 1.35 2012/09/15 15:03:23 obache Exp $
#

DISTNAME=	mysql-ruby-2.8.2
PKGNAME=	${RUBY_PKGPREFIX}-mysql-2.8.2
PKGREVISION=	3
CATEGORIES=	databases ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/51087/ \
		http://tmtm.org/downloads/mysql/ruby/

MAINTAINER=	neumann@s-direktnet.de
HOMEPAGE=	http://www.tmtm.org/en/mysql/ruby/
COMMENT=	Ruby extension for MySQL
LICENSE=	gnu-gpl-v2 OR ruby-license

PKG_DESTDIR_SUPPORT=	user-destdir

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
