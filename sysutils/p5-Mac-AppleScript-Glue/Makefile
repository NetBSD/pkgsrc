# $NetBSD: Makefile,v 1.10 2017/06/05 14:24:36 ryoon Exp $

DISTNAME=	Mac-AppleScript-Glue-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mac/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Mac-AppleScript-Glue/
COMMENT=	Perl 5 module allowing AppleScript to be written in Perl

USE_LANGUAGES=		# empty
ONLY_FOR_PLATFORM=	Darwin-*-*

PERL5_PACKLIST= auto/Mac/AppleScript/Glue/.packlist

DEPENDS+=	p5-Mac-AppleScript>=0.03:../../sysutils/p5-Mac-AppleScript
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
