# $NetBSD: Makefile,v 1.9 2003/07/17 22:54:33 grant Exp $
#

DISTNAME=	Filter-1.16
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fil
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Filter/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 classes representing a number of source filters

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Filter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
