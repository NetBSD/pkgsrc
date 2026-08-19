# $NetBSD: Makefile,v 1.11 2026/08/19 02:35:44 wen Exp $

DISTNAME=	Mail-Transport-4.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MARKOV/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Mail-Transport
COMMENT=	Use Mail Transfer Agents (MTAs)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Mail-Message>=3:../../mail/p5-Mail-Message

PERL5_PACKLIST=	auto/Mail/Transport/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
