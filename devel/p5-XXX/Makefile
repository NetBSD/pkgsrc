# $NetBSD: Makefile,v 1.8 2023/07/06 09:40:26 wiz Exp $

DISTNAME=	XXX-0.38
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IN/INGY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/distribution/XXX/lib/XXX.pod
COMMENT=	Perl function to die with a YAML dump of its arguments
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-YAML-PP>=0.018:../../textproc/p5-YAML-PP

PERL5_PACKLIST=	auto/XXX/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
