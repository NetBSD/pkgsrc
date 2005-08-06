# $NetBSD: Makefile,v 1.13 2005/08/06 06:19:04 jlam Exp $
#

DISTNAME=		bioperl-0.7.0
PKGREVISION=		1
CATEGORIES=		biology
MASTER_SITES=		http://bioperl.org/Core/Latest/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://bioperl.org/
COMMENT=		Perl tools for computational molecular biology

PERL5_PACKLIST=		auto/Bio/.packlist

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bioperl
	cd ${WRKSRC}/examples && ${PAX} -rw . ${PREFIX}/share/examples/bioperl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
