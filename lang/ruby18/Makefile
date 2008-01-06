# $NetBSD: Makefile,v 1.19 2008/01/06 15:45:37 taca Exp $
#

DISTNAME=	# empty
PKGNAME=	${RUBY_PKGPREFIX}-${RUBY_VERSION_SUFFIX}
CATEGORIES=	lang ruby
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT=	Ruby programming language ${RUBY_VERSION} meta package

META_PACKAGE=		yes

DEPENDS+= ${RUBY_PKGPREFIX}-base>=${RUBY_VERSION}:../../lang/ruby18-base
DEPENDS+= ${RUBY_PKGPREFIX}-gdbm>=${RUBY_VERSION}:../../databases/ruby-gdbm
DEPENDS+= ${RUBY_PKGPREFIX}-curses>=${RUBY_VERSION}:../../devel/ruby-curses
DEPENDS+= ${RUBY_PKGPREFIX}-readline>=${RUBY_VERSION}:../../devel/ruby-readline
DEPENDS+= ${RUBY_PKGPREFIX}-tk>=${RUBY_VERSION}:../../x11/ruby-tk

RUBY_VERSION=	${RUBY18_VERSION}

.include "../../lang/ruby/rubyversion.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../mk/bsd.pkg.mk"
