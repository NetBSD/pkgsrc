# $NetBSD: Makefile,v 1.4 2004/04/25 03:52:58 minskim Exp $
#

DISTNAME=		IO-Null-0.02
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5inu
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl module for null filehandles

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Null/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
