# $NetBSD: Makefile,v 1.3 2022/06/28 11:34:44 wiz Exp $

DISTNAME=	Statistics-Basic-1.6611
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JE/JETTERO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Statistics-Basic
COMMENT=	Collection of very basic statistics modules
LICENSE=	gnu-lgpl-v2

DEPENDS+=	p5-Number-Format>=1.42:../../textproc/p5-Number-Format

PERL5_PACKLIST=	auto/Statistics/Basic/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
