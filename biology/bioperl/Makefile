# $NetBSD: Makefile,v 1.8 2003/06/02 01:21:29 jschauma Exp $
#

DISTNAME=		bioperl-0.7.0
CATEGORIES=		biology
MASTER_SITES=		http://bioperl.org/Core/Latest/

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://bioperl.org/
COMMENT=		Perl tools for computational molecular biology

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Bio/.packlist

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bioperl
	cd ${WRKSRC}/examples && ${PAX} -rw . ${PREFIX}/share/examples/bioperl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
