# $NetBSD: Makefile,v 1.1.1.1 2008/03/01 07:17:23 obache Exp $
#

DISTNAME=	ruby-progressbar-0.9
PKGNAME=	${DISTNAME:S/ruby-/${RUBY_PKGPREFIX}-/}
CATEGORIES=	misc ruby
MASTER_SITES=	http://0xcc.net/ruby-progressbar/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://0xcc.net/ruby-progressbar/
COMMENT=	Text Progress Bar Library for Ruby

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS=	${RUBY_DOCDIR}/progressbar ${RUBY_SITELIBDIR}

do-test:
	${RUN} cd ${WRKSRC}; ${RUBY} test.rb

do-install:
	${INSTALL_DATA} ${WRKSRC}/progressbar.rb ${DESTDIR}${RUBY_SITELIBDIR}
.for d in progressbar.en.rd progressbar.ja.rd
	${INSTALL_DATA} ${WRKSRC}/${d} ${DESTDIR}${RUBY_DOCDIR}/progressbar
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
