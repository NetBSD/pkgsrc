# $NetBSD: Makefile,v 1.1.1.1 2001/06/30 08:27:40 taca Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGNAMEPREFIX}readline-${RUBY_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT=	Ruby 1.4 extension to readline library

DEPENDS+=	readline>=4.0:../../devel/readline

DIST_SUBDIR=	ruby
WRKSRC=		${RUBY_WRKSRC}/ext/readline
EXTRACT_ELEMENTS= ${RUBY_DISTNAME}/ext/readline
USE_RUBY_EXTCONF= yes

RUBY_VER=	1.4

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/readline/ja
	${INSTALL_DATA} ${RUBY_WRKSRC}/ext/readline/README \
		${RUBY_DOCDIR}/readline/ja

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
