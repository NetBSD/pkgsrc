# $NetBSD: Makefile,v 1.3 2016/06/08 19:23:34 wiz Exp $

DISTNAME=	Term-ProgressBar-Quiet-0.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LB/LBROCARD/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-ProgressBar-Quiet/
COMMENT=	Provide a progress meter if run interactively
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-Interactive-[0-9]*:../../devel/p5-IO-Interactive
DEPENDS+=	p5-Term-ProgressBar-[0-9]*:../../devel/p5-Term-ProgressBar

PERL5_PACKLIST=		auto/Term/ProgressBar/Quiet/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
