# $NetBSD: Makefile,v 1.7 2005/04/11 21:45:34 tv Exp $

DISTNAME=      	Spiffy-0.22
PKGNAME=       	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/${MODULE_DIR}/${AUTHOR_DIR}/}
MODULE_DIR=	modules/by-module
AUTHOR_DIR=	authors/id/I/IN/INGY

MAINTAINER=	jlam@NetBSD.org
COMMENT=	Object-oriented Perl framework

DEPENDS+=	p5-Filter-[0-9]*:../../textproc/p5-Filter
DEPENDS+=	p5-Scalar-List-Utils-[0-9]*:../../devel/p5-Scalar-List-Utils

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Spiffy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
