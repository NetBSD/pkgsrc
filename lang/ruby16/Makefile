# $NetBSD: Makefile,v 1.5 2005/03/10 06:20:18 taca Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-${RUBY_VERSION}
PKGREVISION=	3
CATEGORIES=	lang ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT=	Ruby programming language ${RUBY_VERSION} meta package

DEPENDS+= ${RUBY_PKGPREFIX}-base>=${RUBY_VERSION}:../../lang/ruby16-base
DEPENDS+= ${RUBY_PKGPREFIX}-dbm>=${RUBY_VERSION}nb1:../../databases/ruby-dbm
DEPENDS+= ${RUBY_PKGPREFIX}-gdbm>=${RUBY_VERSION}nb1:../../databases/ruby-gdbm
DEPENDS+= ${RUBY_PKGPREFIX}-curses>=${RUBY_VERSION}nb2:../../devel/ruby16-curses
DEPENDS+= ${RUBY_PKGPREFIX}-readline>=${RUBY_VERSION}nb1:../../devel/ruby-readline
DEPENDS+= ${RUBY_PKGPREFIX}-digest>=${RUBY_VERSION}nb1:../../security/ruby16-digest
DEPENDS+= ${RUBY_PKGPREFIX}-tcltllib>=${RUBY_VERSION}nb2:../../x11/ruby16-tcltklib
DEPENDS+= ${RUBY_PKGPREFIX}-tk>=${RUBY_VERSION}nb2:../../x11/ruby16-tk

RUBY_VERSION=		${RUBY16_VERSION}
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes

do-install:
	@${ECHO_MSG} This is only a meta package.

.include "../../lang/ruby/rubyversion.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../mk/bsd.pkg.mk"
