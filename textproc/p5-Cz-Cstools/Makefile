# $NetBSD: Makefile,v 1.5 2003/07/17 22:54:33 grant Exp $
#

DISTNAME=	Cstools-3.42
PKGNAME=	p5-Cz-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5cst
CATEGORIES=	textproc converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cz/}

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.fi.muni.cz/~adelton/perl/
COMMENT=	Tools for dealing with Czech and Slovak texts in Perl

DEPENDS+=	p5-MIME-tools>=5.411.1:../../mail/p5-MIME-tools
DEPENDS+=	p5-DBD-XBase>=0.232:../../databases/p5-DBD-XBase

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Cz/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
