# $NetBSD: Makefile,v 1.4 2001/04/05 21:48:40 jtb Exp $
#

DISTNAME=		bioperl-0.7.0
CATEGORIES=		biology
MASTER_SITES=		http://bioperl.org/Core/Latest/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://bioperl.org/
COMMENT=		Perl tools for computational molecular biology

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Bio/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bioperl
	cd ${WRKSRC}/examples; ${GTAR} cf - . \
		| (cd ${PREFIX}/share/examples/bioperl; ${GTAR} xf -)

.include "../../mk/bsd.pkg.mk"
