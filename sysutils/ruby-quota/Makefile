# $NetBSD: Makefile,v 1.5 2004/03/16 02:01:11 taca Exp $
#

DISTNAME=	ruby-quota-0.5.1
CATEGORIES=	sysutils ruby
MASTER_SITES=	http://sourceforge.net/projects/ruby-quota/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/ruby-quota/
COMMENT=	Quota interface for Ruby

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
