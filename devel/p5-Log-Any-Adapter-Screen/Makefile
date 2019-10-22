# $NetBSD: Makefile,v 1.7 2019/10/22 06:11:51 mef Exp $

DISTNAME=	Log-Any-Adapter-Screen-0.140
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PE/PERLANCAR/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Log-Any-Adapter-Screen
COMMENT=	Send logs to screen, with colors and some other features
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Log-Any-[0-9]*:../../devel/p5-Log-Any
DEPENDS+=	p5-Term-ANSIColor-[0-9]*:../../devel/p5-Term-ANSIColor
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes

PERL5_PACKLIST=	auto/Log/Any/Adapter/Screen/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
