# $NetBSD: Makefile,v 1.6 2005/04/11 21:45:32 tv Exp $
#

DISTNAME=		IO-Null-0.02
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5inu
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl module for null filehandles

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Null/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
