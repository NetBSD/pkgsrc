# $NetBSD: Makefile,v 1.44 2019/08/11 13:23:47 wiz Exp $

DISTNAME=	Text-Template-1.55
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Template
COMMENT=	Perl5 library for generating form letters
LICENSE=	artistic AND gnu-gpl-v2

BUILD_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings
BUILD_DEPENDS+=	p5-Test-More-UTF8-[0-9]*:../../devel/p5-Test-More-UTF8

PERL5_PACKLIST=		auto/Text/Template/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
