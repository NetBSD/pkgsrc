# $NetBSD: Makefile,v 1.19 2023/07/06 09:38:30 wiz Exp $
#

DISTNAME=	Template-DBI-2.65
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Template-DBI
COMMENT=	Template interface to the DBI module
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Template-Toolkit>=2.15:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Tie-DBI>=1.05:../../databases/p5-Tie-DBI # only with patches

PERL5_PACKLIST=		auto/Template/DBI/.packlist

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
