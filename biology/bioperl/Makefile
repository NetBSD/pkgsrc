# $NetBSD: Makefile,v 1.5 2001/11/14 14:47:53 agc Exp $
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
	cd ${WRKSRC}/examples && ${PAX} -rw . ${PREFIX}/share/examples/bioperl

.include "../../mk/bsd.pkg.mk"
