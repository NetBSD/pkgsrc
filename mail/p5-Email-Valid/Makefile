# $NetBSD: Makefile,v 1.8 2003/07/21 16:56:48 martti Exp $

DISTNAME=		Email-Valid-0.13
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5emv
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module for testing validity of an email address

DEPENDS+=		p5-MailTools-[0-9]*:../../mail/p5-MailTools
DEPENDS+=		p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Email/Valid/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
