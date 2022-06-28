# $NetBSD: Makefile,v 1.29 2022/06/28 11:34:06 wiz Exp $

DISTNAME=	SVG-2.85
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SVG/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/SVG
COMMENT=	Perl module for generation of SVG images
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/SVG/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
