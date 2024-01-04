# $NetBSD: Makefile,v 1.1 2024/01/04 10:43:23 wiz Exp $

DISTNAME=	Alien-Build-Plugin-Download-GitLab-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PL/PLICEASE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/dist/Alien-Build-Plugin-Download-GitLab
COMMENT=	Alien::Build plugin to download from GitLab
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Alien-Build-[0-9]*:../../devel/p5-Alien-Build
DEPENDS+=	p5-Path-Tiny-[0-9]*:../../filesystems/p5-Path-Tiny
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
TEST_DEPENDS+=	p5-Test2-Suite>=0.000060:../../devel/p5-Test2-Suite

PERL5_PACKLIST=		auto/Alien/Build/Plugin/Download/GitLab/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
