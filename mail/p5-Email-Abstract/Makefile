# $NetBSD: Makefile,v 1.1.1.1 2005/04/18 16:40:26 wiz Exp $

DISTNAME=		Email-Abstract-2.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ema
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Email-Abstract/
COMMENT=		Perl5 module for writing representation-independent mail handling code

DEPENDS+=		p5-Email-Simple>=1.91:../../mail/p5-Email-Simple
DEPENDS+=		p5-Module-Pluggable>=1.5:../../devel/p5-Module-Pluggable

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Email/Abstract/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
