# $NetBSD: Makefile,v 1.3 2015/12/20 05:26:31 taca Exp $
#

DISTNAME=	# empty
PKGNAME=	${RUBY_PKGPREFIX}-${RUBY_VERSION_FULL}
CATEGORIES=	lang ruby
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT=	Ruby programming language ${RUBY_VERSION} meta package
LICENSE=	2-clause-bsd OR ruby-license

META_PACKAGE=		yes

DEPENDS+= ${RUBY_BASE}>=${RUBY_VERSION_FULL}:${RUBY_SRCDIR}
DEPENDS+= ${RUBY_NAME}-gdbm>=${RUBY_VERSION_FULL}:../../databases/ruby-gdbm
DEPENDS+= ${RUBY_NAME}-fiddle>=${RUBY_VERSION_FULL}:../../devel/ruby-fiddle
DEPENDS+= ${RUBY_NAME}-readline>=${RUBY_VERSION_FULL}:../../devel/ruby-readline
DEPENDS+= ${RUBY_NAME}-tk>=${RUBY_VERSION_FULL}:../../x11/ruby-tk

RUBY_VERSION_SUPPORTED=	22

.include "../../lang/ruby/rubyversion.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../mk/bsd.pkg.mk"
