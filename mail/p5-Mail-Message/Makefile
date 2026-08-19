# $NetBSD: Makefile,v 1.26 2026/08/19 01:09:55 wen Exp $

DISTNAME=	Mail-Message-4.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MARKOV/}

MAINTAINER=	angelmadames@gmail.com
HOMEPAGE=	https://metacpan.org/release/Mail-Message
COMMENT=	Object container for MIME-encoded message
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-stringy>=2.1:../../devel/p5-IO-stringy
DEPENDS+=	p5-Scalar-List-Utils>=1.4:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-URI>=1.7:../../www/p5-URI
DEPENDS+=	p5-PathTools>=3.5:../../devel/p5-PathTools
DEPENDS+=	p5-MIME-Types>=2.1:../../mail/p5-MIME-Types
DEPENDS+=	p5-MailTools>=2.1:../../mail/p5-MailTools
DEPENDS+=	p5-TimeDate>=2.3:../../time/p5-TimeDate
DEPENDS+=	p5-User-Identity>=0.94:../../mail/p5-User-Identity
DEPENDS+=	p5-Hash-Case>=1.050:../../devel/p5-Hash-Case

PERL5_PACKLIST=	auto/Mail/Message/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
