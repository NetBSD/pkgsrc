# $NetBSD: Makefile,v 1.13 2005/07/13 18:01:32 jlam Exp $

DISTNAME=		Mail-ListDetector-0.31
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5mli
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Mail-ListDetector/
COMMENT=		Perl5 module to detect whether a message is from a mailing list

DEPENDS+=		p5-MailTools-[0-9]*:../../mail/p5-MailTools
DEPENDS+=		p5-Email-Abstract-[0-9]*:../../mail/p5-Email-Abstract
DEPENDS+=		p5-Email-Valid>=0.12:../../mail/p5-Email-Valid
DEPENDS+=		p5-URI>=1.10:../../www/p5-URI
DEPENDS+=		p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/Mail/ListDetector/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
