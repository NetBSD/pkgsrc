# $NetBSD: Makefile,v 1.14 2007/03/17 15:49:43 taca Exp $

DISTNAME=	racc-${RACC_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-racc-${RACC_VERSION}
CATEGORIES=	devel ruby
MASTER_SITES=	http://i.loveruby.net/archive/racc/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://i.loveruby.net/en/projects/racc/
COMMENT=	LALR(1) parser generator for Ruby

USE_RUBY_SETUP=		yes
RACC_VERSION=		1.4.5

DOCS=		ChangeLog README.en README.ja TODO
DOCS_HTML=	NEWS.html command.html debug.html grammar.html index.html \
		parser.html usage.html
EXAMPLES=	array.y array2.y calc-ja.y calc.y conflict.y hash.y lalr.y \
		syntax.y yyerr.y

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/racc/en
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/racc/ja
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/racc
.endfor
.for f in ${DOCS_HTML}
	${INSTALL_DATA} ${WRKSRC}/doc.en/${f} \
		${RUBY_DOCDIR}/racc/en
	${INSTALL_DATA} ${WRKSRC}/doc.ja/${f} \
		${RUBY_DOCDIR}/racc/ja
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/racc
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} \
		${RUBY_EXAMPLESDIR}/racc
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
