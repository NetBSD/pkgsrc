# $NetBSD: Makefile,v 1.13 2005/07/13 18:01:31 jlam Exp $

DISTNAME=		Email-Valid-0.15
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5emv
PKGREVISION=		1
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Email-Valid/
COMMENT=		Perl5 module for testing validity of an email address

DEPENDS+=		p5-MailTools-[0-9]*:../../mail/p5-MailTools
DEPENDS+=		p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS

PERL5_PACKLIST=		auto/Email/Valid/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
