# $NetBSD: Makefile,v 1.5 2005/01/28 14:08:01 taca Exp $
# FreeBSD: ports/math/ruby-bitvector/Makefile,v 1.1 2000/11/23 14:13:41 knu Exp

DISTNAME=	bitvector-0.1.7
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math ruby
MASTER_SITES=	ftp://ftp.ruby-lang.org/pub/ruby/contrib/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.ruby-lang.org/cgi-bin/cvsweb.cgi/lib/bitvector/
COMMENT=	Efficient Ruby bit vector extension

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
INSTALL_TARGET=		site-install
DOCS=			NOTWRAPPED README TODO

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/bitvector
	${INSTALL_DATA} ${WRKSRC}/tests/* ${RUBY_EXAMPLESDIR}/bitvector
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/bitvector
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/bitvector
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
