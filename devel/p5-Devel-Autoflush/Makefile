# $NetBSD: Makefile,v 1.16 2019/08/11 13:19:14 wiz Exp $

DISTNAME=	Devel-Autoflush-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-Autoflush
COMMENT=	Perl module to set autoflush from the command line
LICENSE=	apache-2.0

BUILD_DEPENDS+=	p5-IO-CaptureOutput>=1.08:../../devel/p5-IO-CaptureOutput

PERL5_PACKLIST=		auto/Devel/Autoflush/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
