# $NetBSD: Makefile,v 1.3 2005/03/06 17:19:06 taca Exp $
# FreeBSD: ports/devel/ruby-racc/Makefile,v 1.20 2001/01/27 09:54:30 knu Exp

DISTNAME=	racc-${RACC_VERSION}-all-2
PKGNAME=	${RUBY_PKGPREFIX}-racc-${RACC_VERSION}
PKGREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.loveruby.net/archive/racc/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.loveruby.net/en/racc.html
COMMENT=	LALR(1) parser generator for Ruby 1.6

DEPENDS+= ${RUBY_PKGPREFIX}-strscan>=0.6.1:../../devel/ruby-strscan

RUBY_VERSION=		${RUBY16_VERSION}
USE_RUBY_SETUP=		YES
RACC_VERSION=		1.4.3
CONFIGURE_ARGS+=	--with=racc,raccrt
WRKSRC=			${WRKDIR}/racc-${RACC_VERSION}-all

DOCS=		BUGS.en BUGS.ja README.en README.ja
DOCS_EN=	changes.html command.html debug.html grammar.html index.html \
		notes.html parser.html usage.html
DOCS_JA=	changes.html command.html debug.html grammar.html index.html \
		notes.html parser.html usage.html
EXAMPLES=	array.y array2.y calc-ja.y calc.y conflict.y hash.y lalr.y \
		syntax.y yyerr.y
COMMANDS=	racc racc2y y2racc

.include "../../lang/ruby/rubyversion.mk"

pre-configure:
	${CP} -p ${WRKSRC}/packages/racc/misc/* ${WRKSRC}/packages/racc/bin
.if ${RUBY_NAME} != "ruby"
.for f in ${COMMANDS}
	${MV} ${WRKSRC}/packages/racc/bin/${f} \
		${WRKSRC}/packages/racc/bin/${f}-${RUBY_VER}
.endfor
.endif

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/racc/en
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/packages/racc/${f} ${RUBY_DOCDIR}/racc
.endfor
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/packages/racc/doc.en/${f} \
		${RUBY_DOCDIR}/racc/en
.endfor
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/racc/ja
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/packages/racc/doc.ja/${f} \
		${RUBY_DOCDIR}/racc/ja
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/racc
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/packages/racc/sample/${f} \
		${RUBY_EXAMPLESDIR}/racc
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
