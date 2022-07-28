# $NetBSD: Makefile,v 1.30 2022/07/28 18:45:03 schmonz Exp $

DISTNAME=	Devel-CheckLib-1.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-CheckLib
COMMENT=	Perl extension to check that a library is available
LICENSE=	${PERL5_LICENSE}

PREV_PKGPATH=	devel/p5-Devel-Checklib

DEPENDS+=	p5-IO-CaptureOutput>=1.08.01:../../devel/p5-IO-CaptureOutput
DEPENDS+=	p5-Capture-Tiny>=0:../../devel/p5-Capture-Tiny

PERL5_PACKLIST=		auto/Devel/CheckLib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
