# $NetBSD: Makefile,v 1.2 2023/07/06 09:40:24 wiz Exp $

DISTNAME=	Types-Path-Tiny-0.006
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DA/DAGOLDEN/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Types-Path-Tiny
COMMENT=	Path::Tiny types and coercions for Moose and Moo

DEPENDS+=	p5-Path-Tiny>=0:../../filesystems/p5-Path-Tiny \
		p5-Type-Tiny>=0.008:../../devel/p5-Type-Tiny

LICENSE=		apache-2.0
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Types/Path/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
