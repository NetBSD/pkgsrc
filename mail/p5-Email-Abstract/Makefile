# $NetBSD: Makefile,v 1.3 2005/08/06 06:19:21 jlam Exp $

DISTNAME=		Email-Abstract-2.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ema
PKGREVISION=		1
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Email-Abstract/
COMMENT=		Perl5 module for writing representation-independent mail handling code

DEPENDS+=		p5-Email-Simple>=1.91:../../mail/p5-Email-Simple
DEPENDS+=		p5-Module-Pluggable>=1.5:../../devel/p5-Module-Pluggable

PERL5_PACKLIST=		auto/Email/Abstract/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
