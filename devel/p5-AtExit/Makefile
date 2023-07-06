# $NetBSD: Makefile,v 1.39 2023/07/06 09:38:37 wiz Exp $

DISTNAME=	AtExit-2.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AtExit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/AtExit
COMMENT=	Provides an ANSI C style atexit() function to Perl programs
LICENSE=	artistic

# for make test
TOOL_DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny

PERL5_PACKLIST=		auto/AtExit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
