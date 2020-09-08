# $NetBSD: Makefile,v 1.9 2020/09/08 13:16:35 wiz Exp $

DISTNAME=	Data-Structure-Util-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
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
