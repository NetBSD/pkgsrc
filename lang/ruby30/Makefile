# $NetBSD: Makefile,v 1.2 2022/01/14 16:16:44 taca Exp $
#

DISTNAME=	# empty
PKGNAME=	${RUBY_PKGPREFIX}-${RUBY_VERSION}
PKGREVISION=	1
CATEGORIES=	lang ruby
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT=	Ruby programming language ${RUBY_VERSION} meta package

META_PACKAGE=		yes

DEPENDS+=	${RUBY_BASE}>=${RUBY_VERSION}:${RUBY_SRCDIR}
DEPENDS+=	${RUBY_NAME}-gdbm>=${RUBY_VERSION}:../../databases/ruby-gdbm
DEPENDS+=	${RUBY_NAME}-readline>=${RUBY_VERSION}:../../devel/ruby-readline

RUBY_VERSIONS_ACCEPTED=	30

.include "../../lang/ruby/rubyversion.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../mk/bsd.pkg.mk"
