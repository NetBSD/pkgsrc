# $NetBSD: Makefile,v 1.12 2019/06/30 20:16:46 nia Exp $

DISTNAME=	Mac-AppleScript-Glue-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mac/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Mac-AppleScript-Glue
COMMENT=	Perl 5 module allowing AppleScript to be written in Perl

USE_LANGUAGES=		# empty
ONLY_FOR_PLATFORM=	Darwin-*-*

PERL5_PACKLIST= auto/Mac/AppleScript/Glue/.packlist

DEPENDS+=	p5-Mac-AppleScript>=0.03:../../sysutils/p5-Mac-AppleScript
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
