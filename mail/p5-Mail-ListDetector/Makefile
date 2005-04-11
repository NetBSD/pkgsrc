# $NetBSD: Makefile,v 1.11 2005/04/11 21:46:21 tv Exp $

DISTNAME=		Mail-ListDetector-0.18
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5mli
PKGREVISION=		1
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module to detect whether a message is from a mailing list

DEPENDS+=		p5-MailTools-[0-9]*:../../mail/p5-MailTools
DEPENDS+=		p5-Email-Valid-[0-9]*:../../mail/p5-Email-Valid
DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=		p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mail/ListDetector/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
