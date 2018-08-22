# $NetBSD: Makefile,v 1.40 2018/08/22 09:47:02 wiz Exp $

DISTNAME=	Text-Template-1.53
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Template/
COMMENT=	Perl5 library for generating form letters
LICENSE=	artistic AND gnu-gpl-v2

BUILD_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings
BUILD_DEPENDS+=	p5-Test-More-UTF8-[0-9]*:../../devel/p5-Test-More-UTF8

PERL5_PACKLIST=		auto/Text/Template/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
