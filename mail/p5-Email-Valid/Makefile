# $NetBSD: Makefile,v 1.10 2004/12/05 19:06:05 he Exp $

DISTNAME=		Email-Valid-0.15
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5emv
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Email-Valid/
COMMENT=		Perl5 module for testing validity of an email address

DEPENDS+=		p5-MailTools-[0-9]*:../../mail/p5-MailTools
DEPENDS+=		p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Email/Valid/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
