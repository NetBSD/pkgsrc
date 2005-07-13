# $NetBSD: Makefile,v 1.5 2005/07/13 18:01:26 jlam Exp $

DISTNAME=	IO-All-0.33
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/${MODULE_DIR}/${AUTHOR_DIR}/}
MODULE_DIR=	modules/by-module
AUTHOR_DIR=	authors/id/I/IN/INGY

MAINTAINER=	jlam@NetBSD.org
COMMENT=	Spiffy OO interface to Perl IO

DEPENDS+=	p5-Filter-[0-9]*:../../textproc/p5-Filter
DEPENDS+=	p5-Spiffy>=0.21:../../devel/p5-Spiffy

PERL5_PACKLIST=		auto/IO/All/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
