# $NetBSD: Makefile,v 1.12 2004/12/25 02:06:55 jlam Exp $

DISTNAME=	Filter-1.30
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fil
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Filter/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 classes representing a number of source filters

USE_BUILDLINK3=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Filter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
