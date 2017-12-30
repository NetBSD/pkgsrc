# $NetBSD: Makefile,v 1.21 2017/12/30 14:21:27 wiz Exp $

DISTNAME=	SVG-2.82
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SVG/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SVG/
COMMENT=	Perl module for generation of SVG images
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/SVG/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
