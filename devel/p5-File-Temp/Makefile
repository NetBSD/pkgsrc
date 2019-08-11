# $NetBSD: Makefile,v 1.42 2019/08/11 13:19:29 wiz Exp $

DISTNAME=	File-Temp-0.2309
PKGNAME=	p5-${DISTNAME:S/09/.09/}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Temp
COMMENT=	Provides functions for generating temporary files
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/Temp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
