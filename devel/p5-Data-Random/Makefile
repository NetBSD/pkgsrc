# $NetBSD: Makefile,v 1.2 2016/06/08 19:22:46 wiz Exp $

DISTNAME=		Data-Random-0.12
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=		phil@cs.wwu.edu
HOMEPAGE=		http://search.cpan.org/dist/Data-Random/
COMMENT=		Perl module to generate random data
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-GD>=1.18:../../graphics/p5-GD
DEPENDS+=		p5-Time-Piece>=1.16:../../time/p5-Time-Piece
BUILD_DEPENDS+=		p5-YAML-Tiny-[0-9]*:../../textproc/p5-YAML-Tiny

PERL5_PACKLIST=	auto/Data/Random/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
