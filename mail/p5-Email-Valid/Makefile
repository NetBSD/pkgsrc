# $NetBSD: Makefile,v 1.5 2002/10/27 20:48:59 seb Exp $

DISTNAME=		Email-Valid-0.13
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5emv
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module for testing validity of an email address

DEPENDS+=		p5-MailTools-[0-9]*:../../mail/p5-MailTools
DEPENDS+=		p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Email/Valid/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
