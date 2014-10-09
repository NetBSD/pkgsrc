# $NetBSD: Makefile,v 1.25 2014/10/09 14:06:11 wiz Exp $

DISTNAME=	AtExit-2.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AtExit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/AtExit/
COMMENT=	Provides an ANSI C style atexit() function to Perl programs
LICENSE=	artistic

PERL5_PACKLIST=		auto/AtExit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
