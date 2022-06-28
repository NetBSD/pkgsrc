# $NetBSD: Makefile,v 1.14 2022/06/28 11:32:28 wiz Exp $

DISTNAME=	File-Slurper-0.013
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Slurper
COMMENT=	Simple, sane and efficient module to slurp a file
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings

PERL5_PACKLIST=		auto/File/Slurper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
