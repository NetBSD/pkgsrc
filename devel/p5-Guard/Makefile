# $NetBSD: Makefile,v 1.14 2018/08/22 09:44:06 wiz Exp $

DISTNAME=	Guard-1.023
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/ML/MLEHMANN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Guard/
COMMENT=	Perl5 module to safe cleanup blocks
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Guard/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
