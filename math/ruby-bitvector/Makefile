# $NetBSD: Makefile,v 1.2 2003/07/17 21:48:08 grant Exp $
# FreeBSD: ports/math/ruby-bitvector/Makefile,v 1.1 2000/11/23 14:13:41 knu Exp

DISTNAME=	bitvector_0-1-6
PKGNAME=	${RUBY_PKGNAMEPREFIX}bitvector-0.1.6
CATEGORIES=	math
MASTER_SITES=	http://www.ce.chalmers.se/~feldt/ruby/extensions/bitvector/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.ce.chalmers.se/~feldt/ruby/extensions/bitvector/
COMMENT=	Efficient Ruby bit vector extension

RUBY_REQD=	1.6
DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF= yes

INSTALL_TARGET=	site-install

DOCS=		NOTWRAPPED README TODO

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/bitvector
	${INSTALL_DATA} ${WRKSRC}/tests/* ${RUBY_EXAMPLESDIR}/bitvector
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/bitvector
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/bitvector
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
