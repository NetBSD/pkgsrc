# $NetBSD: Makefile,v 1.3 2005/01/25 19:32:45 abs Exp $

DISTNAME=      	Spoon-0.21
PKGNAME=       	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/${MODULE_DIR}/${AUTHOR_DIR}/}
MODULE_DIR=	modules/by-module
AUTHOR_DIR=	authors/id/I/IN/INGY

MAINTAINER=	jlam@NetBSD.org
COMMENT=	Spiffy Application Building Framework

DEPENDS+=	p5-IO-All>=0.32:../../devel/p5-IO-All
DEPENDS+=	p5-Spiffy>=0.21:../../devel/p5-Spiffy
DEPENDS+=	p5-Template-Toolkit>=2.10:../../www/p5-Template-Toolkit

USE_BUILDLINK3=	yes
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Spoon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
