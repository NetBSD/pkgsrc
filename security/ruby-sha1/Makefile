# $NetBSD: Makefile,v 1.2 2002/03/17 15:25:43 taca Exp $
# FreeBSD: ports/converters/ruby-sha1/Makefile,v 1.2 2000/11/03 18:14:37 knu Exp

DISTNAME=	ruby-sha1-${VERSION}
PKGNAME=	${RUBY_PKGNAMEPREFIX}sha1-${VERSION}
CATEGORIES=	security
MASTER_SITES=	http://www.omcl.org/~spcoltri/ruby/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.omcl.org/~spcoltri/ruby/ruby-sha1.html
COMMENT=	Ruby interface to the SHA-1 Secure Hash Algorithm

VERSION=	1.2
DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF= yes

RUBY_VER=	1.4		# now this is for ruby 1.4 only.

INSTALL_TARGET=	site-install

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/sha1
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/sha1

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
