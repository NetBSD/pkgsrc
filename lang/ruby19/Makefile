# $NetBSD: Makefile,v 1.2 2011/10/20 15:12:36 taca Exp $
#

DISTNAME=	# empty
PKGNAME=	${RUBY_PKGPREFIX}-${RUBY_VERSION_SUFFIX}
PKGREVISION=	1
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
DEPENDS+= ${RUBY_PKGPREFIX}-fiddle>=${RUBY_VERSION_SUFFIX}:../../devel/ruby-fiddle
DEPENDS+= ${RUBY_PKGPREFIX}-readline>=${RUBY_VERSION_SUFFIX}:../../devel/ruby-readline
DEPENDS+= ${RUBY_PKGPREFIX}-psych>=${RUBY_VERSION_SUFFIX}:../../textproc/ruby-psych
DEPENDS+= ${RUBY_PKGPREFIX}-tk>=${RUBY_VERSION_SUFFIX}:../../x11/ruby-tk

RUBY_VERSION=	${RUBY19_VERSION}

.include "../../lang/ruby/rubyversion.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../mk/bsd.pkg.mk"
