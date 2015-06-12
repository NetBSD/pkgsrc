# $NetBSD: Makefile,v 1.6 2015/06/12 10:50:16 wiz Exp $
#

DISTNAME=	Switch-2.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RG/RGARCIA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Switch/
COMMENT=	Switch statement for Perl
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Text-Balanced-[0-9]*:../../textproc/p5-Text-Balanced
DEPENDS+=	p5-Filter-[0-9]*:../../textproc/p5-Filter

PERL5_PACKLIST=	auto/Switch/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
