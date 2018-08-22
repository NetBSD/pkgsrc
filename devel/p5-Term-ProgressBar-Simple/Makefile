# $NetBSD: Makefile,v 1.5 2018/08/22 09:44:42 wiz Exp $

DISTNAME=	Term-ProgressBar-Simple-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EV/EVDB/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-ProgressBar-Simple/
COMMENT=	Simpler progress bars

DEPENDS+=	p5-Term-ProgressBar-Quiet-[0-9]*:../../devel/p5-Term-ProgressBar-Quiet

PERL5_PACKLIST=		auto/Term/ProgressBar/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
