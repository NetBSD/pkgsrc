# $NetBSD: Makefile,v 1.6 2004/03/07 14:32:28 taca Exp $
# FreeBSD: ports/devel/ruby-racc/Makefile,v 1.20 2001/01/27 09:54:30 knu Exp

DISTNAME=	racc-1.4.4
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.loveruby.net/archive/racc/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.loveruby.net/en/racc.html
COMMENT=	LALR(1) parser generator for Ruby

DEPENDS+= ${RUBY_PKGNAMEPREFIX}strscan>=0.6.1:../../devel/ruby-strscan

CONFLICTS=	racc-runtime-*

DIST_SUBDIR=	ruby
USE_RUBY=	yes
USE_RUBY_SETUP=	yes

DOCS=		ChangeLog NEWS.en NEWS.ja README.en README.ja
DOCS_EN=	NEWS.html command.html debug.html grammar.html index.html \
		parser.html usage.html
DOCS_JA=	NEWS.html command.html debug.html grammar.html index.html \
		parser.html usage.html
EXAMPLES=	array.y array2.y calc-ja.y calc.y conflict.y hash.y lalr.y \
		syntax.y yyerr.y

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/racc/en
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/racc
.endfor
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/doc.en/${f} \
		${RUBY_DOCDIR}/racc/en
.endfor
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/racc/ja
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/doc.ja/${f} \
		${RUBY_DOCDIR}/racc/ja
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/racc
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} \
		${RUBY_EXAMPLESDIR}/racc
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
