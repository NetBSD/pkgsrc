# $NetBSD: Makefile,v 1.2 2001/08/13 09:20:40 agc Exp $
# FreeBSD: ports/devel/ruby-racc/Makefile,v 1.20 2001/01/27 09:54:30 knu Exp

DISTNAME=	racc-${RACC_VERSION}
PKGNAME?=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.xdsl.ne.jp/Cd/aamine/soft/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.xdsl.ne.jp/Cd/aamine/
COMMENT=	LALR(1) parser generator for Ruby

RACC_VERSION=	1.3.9

DIST_SUBDIR=	ruby
USE_RUBY=	yes
USE_RUBY_AMSTD=	yes
USE_RUBY_SETUP=	yes

.if !defined(RUNTIME)
DEPENDS+= ${RUBY_PKGNAMEPREFIX}racc-runtime-${RACC_VERSION}:../../devel/ruby-racc-runtime
DEPENDS+= ${RUBY_PKGNAMEPREFIX}strscan>=0.6.1:../../devel/ruby-strscan

REPLACE_RUBY=	misc/racc2y misc/y2racc

DOCS_EN=	changes.html command.html debug.html grammer.html index.html \
		parser.html usage.html
DOCS_JA=	changes.html command.html debug.html grammer.html index.html \
		parser.html usage.html
EXAMPLES=	array.y array2.y calc-ja.y calc.y conflict.y hash.y lalr.y \
		syntax.y yyerr.y
.endif

pre-patch:
	${RUBY} -i -ne '/^amstd\b/ || /^strscan\b/ || print' ${WRKSRC}/lib/PATHCONV
	${RM} -rf ${WRKSRC}/lib/amstd ${WRKSRC}/lib/strscan
.if defined(RUNTIME)
	${RUBY} -i -ne '/^racc\b/ || print' ${WRKSRC}/bin/PATHCONV
	${RM} -rf ${WRKSRC}/bin/racc
	${RUBY} -i -ne '/^strscanso\b/ || print' ${WRKSRC}/ext/PATHCONV
	${RM} -rf ${WRKSRC}/ext/strscanso
	${RUBY} -i -ne '/^racc\b/ || print' ${WRKSRC}/lib/PATHCONV
	${RM} -rf ${WRKSRC}/lib/racc
.else
	${RM} -rf ${WRKSRC}/ext
	${RUBY} -i -ne '/^raccrt\b/ || print' ${WRKSRC}/lib/PATHCONV
	${RM} -rf ${WRKSRC}/lib/raccrt
.endif

.if defined(RUNTIME)
pre-install:
	${INSTALL_DATA_DIR} ${RUBY_SITELIBDIR}/racc
	${INSTALL_DATA_DIR} ${RUBY_SITEARCHLIBDIR}/racc
.else
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/racc/racc \
		${WRKSRC}/misc/racc2y ${WRKSRC}/misc/y2racc ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/racc
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${RUBY_EXAMPLESDIR}/racc
.endfor
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/racc/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/doc.en/${f} ${RUBY_DOCDIR}/racc
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/doc.ja/${f} ${RUBY_DOCDIR}/racc/ja
.endfor
.endif

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
