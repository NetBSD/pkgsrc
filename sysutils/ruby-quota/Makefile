# $NetBSD: Makefile,v 1.1.1.1 2002/03/30 16:52:41 taca Exp $
#

DISTNAME=	ruby-quota-0.5.1
CATEGORIES=	sysutils
MASTER_SITES=	http://kt-www.jaist.ac.jp/~ttate/ftp/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://kt-www.jaist.ac.jp/~ttate/ruby/ruby-ext.html
COMMENT=	quota interface for Ruby

DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF= yes
INSTALL_TARGET=	site-install

DOCS=		ChangeLog README
DOCSDIR=	${RUBY_DOCDIR}/quota

post-install:
	${INSTALL_DATA_DIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}/$f
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
