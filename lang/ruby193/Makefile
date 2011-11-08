# $NetBSD: Makefile,v 1.1.1.1 2011/11/08 16:12:25 taca Exp $
#

DISTNAME=	# empty
PKGNAME=	${RUBY_PKGPREFIX}-${RUBY_VERSION_FULL}
CATEGORIES=	lang ruby
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT=	Ruby programming language ${RUBY_VERSION} meta package
LICENSE=	gnu-gpl-v2 OR ruby-license

META_PACKAGE=		yes

DEPENDS+= ${RUBY_PKGPREFIX}-base>=${RUBY_VERSION_FULL}:../../lang/${RUBY_NAME}-base
DEPENDS+= ${RUBY_PKGPREFIX}-gdbm>=${RUBY_VERSION_FULL}:../../databases/ruby-gdbm
DEPENDS+= ${RUBY_PKGPREFIX}-curses>=${RUBY_VERSION_FULL}:../../devel/ruby-curses
DEPENDS+= ${RUBY_PKGPREFIX}-fiddle>=${RUBY_VERSION_FULL}:../../devel/ruby-fiddle
DEPENDS+= ${RUBY_PKGPREFIX}-readline>=${RUBY_VERSION_FULL}:../../devel/ruby-readline
DEPENDS+= ${RUBY_PKGPREFIX}-tk>=${RUBY_VERSION_FULL}:../../x11/ruby-tk

RUBY_VERSION_SUPPORTED=	193

.include "../../lang/ruby/rubyversion.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../mk/bsd.pkg.mk"
