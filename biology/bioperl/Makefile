# $NetBSD: Makefile,v 1.10 2004/04/11 03:50:56 snj Exp $
#

DISTNAME=		bioperl-0.7.0
CATEGORIES=		biology
MASTER_SITES=		http://bioperl.org/Core/Latest/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://bioperl.org/
COMMENT=		Perl tools for computational molecular biology

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Bio/.packlist

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bioperl
	cd ${WRKSRC}/examples && ${PAX} -rw . ${PREFIX}/share/examples/bioperl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
