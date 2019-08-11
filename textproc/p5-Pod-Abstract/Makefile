# $NetBSD: Makefile,v 1.13 2019/08/11 13:23:34 wiz Exp $
#

DISTNAME=	Pod-Abstract-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Pod-Abstract
COMMENT=	Abstract document tree for Perl POD documents
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Pod/Abstract/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
