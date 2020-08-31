# $NetBSD: Makefile,v 1.43 2020/08/31 18:08:04 wiz Exp $

DISTNAME=	File-Temp-0.2309
PKGNAME=	p5-${DISTNAME:S/09/.09/}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Temp
COMMENT=	Provides functions for generating temporary files
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/Temp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
