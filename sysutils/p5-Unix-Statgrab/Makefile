# $NetBSD: Makefile,v 1.8 2017/06/05 14:24:37 ryoon Exp $

DISTNAME=	Unix-Statgrab-0.111
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RE/REHSACK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Unix-Statgrab
COMMENT=	Perl extension for collecting information about the machine
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Config-AutoConf>=0.19:../../devel/p5-Config-AutoConf
BUILD_DEPENDS+=	p5-Module-Build>=0.4000:../../devel/p5-Module-Build
BUILD_DEPENDS+=	p5-Test-LeakTrace-[0-9]*:../../devel/p5-Test-LeakTrace

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config
PERL5_PACKLIST=		auto/Unix/Statgrab/.packlist
PERL5_REQD+=	5.2	# File::Copy >= 0
PERL5_REQD+=	5.10.1	# parent >= 0
PERL5_REQD+=	5.11.2	# ExtUtils::CBuilder >= 0.27

.include "../../devel/libstatgrab/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
