# $NetBSD: Makefile,v 1.2 2002/10/07 15:09:25 hubertf Exp $
#

DISTNAME=	Cstools-3.3
PKGNAME=	p5-Cz-${DISTNAME}
SVR4_PKGNAME=	p5cst
CATEGORIES=	textproc converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cz/}

MAINTAINER=	salo@Xtrmntr.org
HOMEPAGE=	http://www.fi.muni.cz/~adelton/perl/
COMMENT=	Tools for dealing with Czech and Slovak texts in Perl

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Cz/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
