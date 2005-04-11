# $NetBSD: Makefile,v 1.11 2005/04/11 21:45:00 tv Exp $
#

DISTNAME=		bioperl-0.7.0
CATEGORIES=		biology
MASTER_SITES=		http://bioperl.org/Core/Latest/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://bioperl.org/
COMMENT=		Perl tools for computational molecular biology

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Bio/.packlist

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bioperl
	cd ${WRKSRC}/examples && ${PAX} -rw . ${PREFIX}/share/examples/bioperl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
