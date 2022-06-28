# $NetBSD: Makefile,v 1.11 2022/06/28 11:32:12 wiz Exp $

DISTNAME=	Data-Structure-Util-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AN/ANDYA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Data::Structure::Util
COMMENT=	Change nature of data within a structure
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Data/Structure/Util/.packlist
USE_LANGUAGES=	c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
