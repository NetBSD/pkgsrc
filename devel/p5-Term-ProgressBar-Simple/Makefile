# $NetBSD: Makefile,v 1.7 2019/08/11 13:20:25 wiz Exp $

DISTNAME=	Term-ProgressBar-Simple-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EV/EVDB/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Term-ProgressBar-Simple
COMMENT=	Simpler progress bars

DEPENDS+=	p5-Term-ProgressBar-Quiet-[0-9]*:../../devel/p5-Term-ProgressBar-Quiet

PERL5_PACKLIST=		auto/Term/ProgressBar/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
