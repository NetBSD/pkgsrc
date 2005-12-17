# $NetBSD: Makefile,v 1.9 2005/12/17 05:20:22 jlam Exp $

DISTNAME=      	Spoon-0.23
PKGNAME=       	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/${MODULE_DIR}/${AUTHOR_DIR}/}
MODULE_DIR=	modules/by-module
AUTHOR_DIR=	authors/id/I/IN/INGY

MAINTAINER=	jlam@pkgsrc.org
COMMENT=	Spiffy Application Building Framework

DEPENDS+=	p5-IO-All>=0.32:../../devel/p5-IO-All
DEPENDS+=	p5-Spiffy>=0.22:../../devel/p5-Spiffy
DEPENDS+=	p5-Template-Toolkit>=2.10:../../www/p5-Template-Toolkit

PERL5_PACKLIST=	auto/Spoon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
