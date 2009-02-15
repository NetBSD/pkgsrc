# $NetBSD: Makefile,v 1.1.1.1 2009/02/15 03:04:18 taca Exp $
# $FreeBSD: ports/devel/ruby-setup.rb/Makefile,v 1.20 2006/06/08 20:25:19 sem Exp $
#

DISTNAME=	setup-3.4.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.loveruby.net/archive/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.loveruby.net/en/setup.html
COMMENT=	Common installer script for ruby packages

NO_BUILD=	yes

DOCS_EN=	doc.en/* NEWS.en Usage_en.txt README.en ChangeLog TODO
DOCS_JA=	doc.ja/* NEWS.ja Usage_ja.txt README.ja
REPLACE_RUBY=	setup.rb

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin ${RUBY_DOC}/setup/ja ${RUBY_EG}/setup \
			${RUBY_VENDORLIB}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/setup.rb \
		${DESTDIR}${PREFIX}/bin/${RUBY_PKGPREFIX}-setup
	${INSTALL_DATA} ${WRKSRC}/setup.rb ${DESTDIR}${PREFIX}/${RUBY_VENDORLIB}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/setup
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/setup/ja
.endfor
	${INSTALL_DATA} ${WRKSRC}/sample/* ${DESTDIR}${PREFIX}/${RUBY_EG}/setup

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
