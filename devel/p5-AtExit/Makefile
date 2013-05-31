# $NetBSD: Makefile,v 1.22 2013/05/31 12:40:04 wiz Exp $

DISTNAME=	AtExit-2.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
SVR4_PKGNAME=	p5ate
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AtExit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/AtExit/
COMMENT=	Provides an ANSI C style atexit() function to Perl programs
LICENSE=	artistic

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/AtExit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
