# $NetBSD: Makefile,v 1.1.1.1 2001/06/30 08:17:03 taca Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGNAMEPREFIX}md5-${RUBY_VERSION}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT=	Ruby extension to MD5 library

DISTINFO_FILE=	${RUBY_DISTINFO}
WRKSRC=		${RUBY_WRKSRC}/ext/md5

DIST_SUBDIR=	ruby
EXTRACT_ELEMENTS= ${RUBY_DISTNAME}/ext/md5
USE_RUBY_EXTCONF= yes

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/md5/ja
	${INSTALL_DATA} ${WRKSRC}/md5.txt ${RUBY_DOCDIR}/md5
	${INSTALL_DATA} ${WRKSRC}/md5.txt.jp ${RUBY_DOCDIR}/md5/ja/md5.txt.ja

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
