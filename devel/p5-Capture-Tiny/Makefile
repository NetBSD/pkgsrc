# $NetBSD: Makefile,v 1.35 2019/08/11 13:18:57 wiz Exp $

DISTNAME=	Capture-Tiny-0.48
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DA/DAGOLDEN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Capture-Tiny
COMMENT=	Capture STDOUT and STDERR from Perl, XS or external programs
LICENSE=	apache-2.0

PERL5_PACKLIST=		auto/Capture/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
