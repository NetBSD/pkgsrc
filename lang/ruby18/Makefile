# $NetBSD: Makefile,v 1.20 2010/09/10 03:37:05 taca Exp $
#

DISTNAME=	# empty
PKGNAME=	${RUBY_PKGPREFIX}-${RUBY_VERSION_SUFFIX}
CATEGORIES=	lang ruby
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT=	Ruby programming language ${RUBY_VERSION} meta package
LICENSE=	gnu-gpl-v2 OR ruby-license

META_PACKAGE=		yes

DEPENDS+= ${RUBY_PKGPREFIX}-base>=${RUBY_VERSION_SUFFIX}:../../lang/${RUBY_NAME}-base
DEPENDS+= ${RUBY_PKGPREFIX}-gdbm>=${RUBY_VERSION_SUFFIX}:../../databases/ruby-gdbm
DEPENDS+= ${RUBY_PKGPREFIX}-curses>=${RUBY_VERSION_SUFFIX}:../../devel/ruby-curses
DEPENDS+= ${RUBY_PKGPREFIX}-readline>=${RUBY_VERSION_SUFFIX}:../../devel/ruby-readline
DEPENDS+= ${RUBY_PKGPREFIX}-tk>=${RUBY_VERSION_SUFFIX}:../../x11/ruby-tk

RUBY_VERSION=	${RUBY18_VERSION}

.include "../../lang/ruby/rubyversion.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../mk/bsd.pkg.mk"
