# $NetBSD: Makefile,v 1.10 2020/09/08 13:16:38 wiz Exp $

DISTNAME=	Sub-Info-0.002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXODIST/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Sub::Info
COMMENT=	Tool to inspect subroutines
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Importer-[0-9]*:../../devel/p5-Importer

PERL5_PACKLIST=	auto/Sub/Info/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
