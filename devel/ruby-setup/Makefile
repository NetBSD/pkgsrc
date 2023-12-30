# $NetBSD: Makefile,v 1.7 2023/12/30 21:29:43 zafer Exp $

DISTNAME=	setup-3.4.1
PKGREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	https://i.loveruby.net/archive/setup/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.loveruby.net/en/setup.html
COMMENT=	Common installer script for ruby packages
LICENSE=	gnu-lgpl-v2.1

NO_BUILD=	yes

DOCS_EN=	doc.en/* NEWS.en Usage_en.txt README.en ChangeLog TODO
DOCS_JA=	doc.ja/* NEWS.ja Usage_ja.txt README.ja
REPLACE_RUBY=	setup.rb

INSTALLATION_DIRS=	bin ${RUBY_DOC}/setup/ja ${RUBY_EG}/setup \
			${RUBY_VENDORLIB}

PLIST_SUBST+=		RUBY_PKGPREFIX=${RUBY_PKGPREFIX:Q}

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
