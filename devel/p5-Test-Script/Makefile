# $NetBSD: Makefile,v 1.27 2019/08/11 13:20:36 wiz Exp $

DISTNAME=	Test-Script-1.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/A/AD/ADAMK/
COMMENT=	Test::Script - Cross-platform basic tests for scripts
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Probe-Perl>=0.01:../../devel/p5-Probe-Perl
DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-Test2-Suite>=0.000077:../../devel/p5-Test2-Suite

PERL5_PACKLIST=		auto/Test/Script/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
