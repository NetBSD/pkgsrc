# $NetBSD: Makefile,v 1.7 2002/10/06 22:31:05 seb Exp $
#

DISTNAME=	Filter-1.16
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fil
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Filter/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl5 classes representing a number of source filters

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Filter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
