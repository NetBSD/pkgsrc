# $NetBSD: Makefile,v 1.10 2005/03/06 17:19:06 taca Exp $
# FreeBSD: ports/devel/ruby-racc/Makefile,v 1.20 2001/01/27 09:54:30 knu Exp

DISTNAME=	racc-${RACC_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-racc-${RACC_VERSION}
PKGREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.loveruby.net/archive/racc/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.loveruby.net/en/racc.html
COMMENT=	LALR(1) parser generator for Ruby

RUBY_VERSION_SUPPORTED=	18
USE_RUBY_SETUP=		yes
RACC_VERSION=		1.4.4

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
