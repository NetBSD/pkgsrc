# $NetBSD: Makefile,v 1.3 2003/01/15 11:43:26 salo Exp $
#

DISTNAME=	Cstools-3.42
PKGNAME=	p5-Cz-${DISTNAME}
SVR4_PKGNAME=	p5cst
CATEGORIES=	textproc converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cz/}

MAINTAINER=	salo@netbsd.org
HOMEPAGE=	http://www.fi.muni.cz/~adelton/perl/
COMMENT=	Tools for dealing with Czech and Slovak texts in Perl

DEPENDS+=	p5-MIME-tools>=5.411.1:../../mail/p5-MIME-tools

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Cz/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
