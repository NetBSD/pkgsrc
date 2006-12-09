# $NetBSD: Makefile,v 1.14.2.1 2006/12/09 10:17:47 salo Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-${RUBY_VERSION_SUFFIX}
#PKGREVISION=
CATEGORIES=	lang ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT=	Ruby programming language ${RUBY_VERSION} meta package

DEPENDS+= ${RUBY_PKGPREFIX}-base>=${RUBY_VERSION}:../../lang/ruby18-base
DEPENDS+= ${RUBY_PKGPREFIX}-gdbm>=${RUBY_VERSION}:../../databases/ruby-gdbm
DEPENDS+= ${RUBY_PKGPREFIX}-curses>=${RUBY_VERSION}:../../devel/ruby-curses
DEPENDS+= ${RUBY_PKGPREFIX}-readline>=${RUBY_VERSION}:../../devel/ruby-readline
DEPENDS+= ${RUBY_PKGPREFIX}-tk>=${RUBY_VERSION}:../../x11/ruby-tk

RUBY_VERSION=	${RUBY18_VERSION}
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	@${ECHO_MSG} This is only a meta package.

.include "../../lang/ruby/rubyversion.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../mk/bsd.pkg.mk"
