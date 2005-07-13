# $NetBSD: Makefile,v 1.3 2005/07/13 18:01:26 jlam Exp $
#

DISTNAME=		IO-Multiplex-1.08
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5imx
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl module to manage IO on many file handles

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/IO/Multiplex/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
