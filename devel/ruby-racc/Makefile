# $NetBSD: Makefile,v 1.3 2001/12/30 17:13:47 taca Exp $
# FreeBSD: ports/devel/ruby-racc/Makefile,v 1.20 2001/01/27 09:54:30 knu Exp

DISTNAME=	${RACC_DISTFILE}
PKGNAME?=	${RACC_NAME}-${RACC_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${RACC_SITES}

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	${RACC_HOMEPAGE}
COMMENT=	LALR(1) parser generator for Ruby

DEPENDS+= ${RACC_NAME}-runtime>=${RACC_VERSION}:../../devel/ruby-racc-runtime
DEPENDS+= ${RUBY_PKGNAMEPREFIX}strscan>=0.6.1:../../devel/ruby-strscan

CONFIGURE_ARGS+=--with=racc

DOCS=		BUGS.en BUGS.ja README.en README.ja
DOCS_EN=	changes.html command.html debug.html grammar.html index.html \
		parser.html usage.html
DOCS_JA=	changes.html command.html debug.html grammar.html index.html \
		parser.html usage.html
EXAMPLES=	array.y array2.y calc-ja.y calc.y conflict.y hash.y lalr.y \
		syntax.y yyerr.y

pre-configure:
	${CP} -p ${WRKSRC}/packages/racc/misc/* ${WRKSRC}/packages/racc/bin

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/racc
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/packages/racc/sample/${f} \
		${RUBY_EXAMPLESDIR}/racc
.endfor
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/racc/en
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/racc/ja
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/packages/racc/${f} ${RUBY_DOCDIR}/racc
.endfor
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/packages/racc/doc.en/${f} \
		${RUBY_DOCDIR}/racc/en
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/packages/racc/doc.ja/${f} \
		${RUBY_DOCDIR}/racc/ja
.endfor

.include "Makefile.common"
