# $NetBSD: Makefile,v 1.4 2017/06/05 14:23:18 ryoon Exp $

DISTNAME=	MooX-late-0.015
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TO/TOBYINK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooX-late/
COMMENT=	Easily translate Moose code to Moo
LICENSE=	gnu-gpl-v1 OR artistic

DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny

BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

PERL5_PACKLIST=	auto/MooX/late/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
