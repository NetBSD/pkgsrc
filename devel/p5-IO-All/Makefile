# $NetBSD: Makefile,v 1.2 2004/12/25 05:08:05 jlam Exp $

DISTNAME=	IO-All-0.33
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/${MODULE_DIR}/${AUTHOR_DIR}/}
MODULE_DIR=	module/by-module
AUTHOR_DIR=	authors/id/I/IN/INGY

MAINTAINER=	jlam@NetBSD.org
COMMENT=	Spiffy OO interface to Perl IO

DEPENDS+=	p5-Filter-[0-9]*:../../textproc/p5-Filter
DEPENDS+=	p5-Spiffy>=0.21:../../devel/p5-Spiffy

USE_BUILDLINK3=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/All/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
