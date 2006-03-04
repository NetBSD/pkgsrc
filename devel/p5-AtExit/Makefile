# $NetBSD: Makefile,v 1.15 2006/03/04 21:29:19 jlam Exp $
#

DISTNAME=	AtExit-2.01
PKGNAME=	p5-AtExit-2.01
SVR4_PKGNAME=	p5ate
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AtExit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Provides an ANSI C style atexit() function to Perl programs

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/AtExit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
