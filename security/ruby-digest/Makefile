# $NetBSD: Makefile,v 1.6 2004/01/20 12:25:34 agc Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGNAMEPREFIX}digest-${RUBY_VERSION}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT=	Ruby extension to message digest library

CONFLICTS=	${RUBY_PKGNAMEPREFIX}md5-[0-9]*

DISTINFO_FILE=	${RUBY_DISTINFO}

WRKSRC=		${RUBY_WRKSRC}/ext/digest
DIST_SUBDIR=	ruby
RUBY_REQD=	1.6.6
EXTRACT_ELEMENTS= ${RUBY_DISTNAME}/ext/digest
USE_RUBY_EXTCONF= yes
RUBY_EXTCONF_SUBDIRS=	. md5 rmd160 sha1 sha2
REPLACE_RUBY=	test.rb
RUBY_DOCS=	digest.txt digest.txt.ja

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/digest
.for file in ${RUBY_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${RUBY_DOCDIR}/digest
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
