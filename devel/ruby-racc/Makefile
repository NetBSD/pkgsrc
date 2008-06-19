# $NetBSD: Makefile,v 1.15 2008/06/19 14:47:54 taca Exp $

DISTNAME=	racc-${RACC_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-racc-${RACC_VERSION}
PKGREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://i.loveruby.net/archive/racc/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://i.loveruby.net/en/projects/racc/
COMMENT=	LALR(1) parser generator for Ruby

USE_RUBY_SETUP=		yes
RACC_VERSION=		1.4.5

CONFIGURE_ARGS+=	--siteruby=${PREFIX}/${RUBY_VENDORLIB_BASE} \
			--siterubyver=${PREFIX}/${RUBY_VENDORLIB} \
			--siterubyverarch=${PREFIX}/${RUBY_VENDORARCHLIB}
INSTALLATION_DIRS=	${RUBY_DOC}/racc/en ${RUBY_DOC}/racc/ja \
			${RUBY_EG}/racc

DOCS=		ChangeLog README.en README.ja TODO
DOCS_HTML=	NEWS.html command.html debug.html grammar.html index.html \
		parser.html usage.html
EXAMPLES=	array.y array2.y calc-ja.y calc.y conflict.y hash.y lalr.y \
		syntax.y yyerr.y

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/racc
.endfor
.for f in ${DOCS_HTML}
	${INSTALL_DATA} ${WRKSRC}/doc.en/${f} \
		${DESTDIR}${PREFIX}/${RUBY_DOC}/racc/en
	${INSTALL_DATA} ${WRKSRC}/doc.ja/${f} \
		${DESTDIR}${PREFIX}/${RUBY_DOC}/racc/ja
.endfor
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} \
		${DESTDIR}${PREFIX}/${RUBY_EG}/racc
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
