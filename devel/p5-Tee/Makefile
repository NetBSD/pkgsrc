# $NetBSD: Makefile,v 1.18 2022/06/28 11:33:17 wiz Exp $
#

DISTNAME=	Tee-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DA/DAGOLDEN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Tee
COMMENT=	Pure Perl emulation of GNU tee

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Tee/.packlist

DEPENDS+=	p5-Probe-Perl>=0:../../devel/p5-Probe-Perl
DEPENDS+=	p5-IPC-Run3>=0.033:../../devel/p5-IPC-Run3
DEPENDS+=	p5-IO-CaptureOutput-[0-9]*:../../devel/p5-IO-CaptureOutput

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
