# $NetBSD: Makefile,v 1.1.1.1 2004/12/22 15:49:27 kim Exp $
#

DISTNAME=		IO-Multiplex-1.08
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5imx
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl module to manage IO on many file handles

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Multiplex/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
