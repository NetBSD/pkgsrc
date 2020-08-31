# $NetBSD: Makefile,v 1.2 2020/08/31 18:09:14 wiz Exp $

DISTNAME=	XXX-0.35
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/I/IN/INGY/
COMMENT=	Perl function to die with a YAML dump of its arguments
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-YAML-PP>=0.018:../../textproc/p5-YAML-PP

PERL5_PACKLIST=	auto/XXX/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
