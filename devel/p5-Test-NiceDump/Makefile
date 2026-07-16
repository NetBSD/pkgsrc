# $NetBSD: Makefile,v 1.10 2026/07/16 19:03:34 wiz Exp $

DISTNAME=	Test-NiceDump-1.0.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DA/DAKKAR/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Test::NiceDump
COMMENT=	Let's have a nice and human readable dump of our objects!
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/NiceDump/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
