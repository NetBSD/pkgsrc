# $NetBSD: Makefile,v 1.34 2022/06/28 11:33:52 wiz Exp $

DISTNAME=	Path-Tiny-0.118
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	filesystems devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DA/DAGOLDEN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Path-Tiny
COMMENT=	Perl5 file path utility
LICENSE=	apache-2.0

PERL5_PACKLIST=		auto/Path/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
