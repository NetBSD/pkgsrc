# $NetBSD: Makefile,v 1.1.1.1 2003/09/15 00:18:31 dmcmahill Exp $

DISTNAME=	ruby-gsl-0.1.9
WRKSRC=		${WRKDIR}/${DISTNAME}/ext
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ruby-gsl/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://ruby-gsl.sourceforge.net/
COMMENT=	Wrapper of the GNU Scientific Library (GSL) for Ruby

DIST_SUBDIR=		ruby
USE_RUBY_EXTCONF=	yes
USE_BUILDLINK2=		yes
INSTALL_TARGET=		site-install

DOCS=		README

post-patch:
	${MV} ${WRKSRC}/Const.c ${WRKSRC}/Const.c.bak
	${SED} -e 's;CONST_MKS_;CONST_MKSA_;g' -e 's;CONST_CGS_;CONST_CGSM_;g' \
		${WRKSRC}/Const.c.bak > ${WRKSRC}/Const.c

DOCS=	\
	HOWTO \
	IMPLEMENTED \
	README \
	TODO \
	doc.rd

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/gsl
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/../doc/${f} ${RUBY_DOCDIR}/gsl
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/gsl
	${INSTALL_DATA} ${WRKSRC}/../samples/*.rb ${RUBY_EXAMPLESDIR}/gsl

.include "../../lang/ruby-base/Makefile.common"
.include "../../lang/ruby-base/buildlink2.mk"
.include "../../math/gsl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
