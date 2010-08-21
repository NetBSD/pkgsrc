# $NetBSD: Makefile,v 1.18 2010/08/21 16:33:12 seb Exp $
#

DISTNAME=	AtExit-2.01
PKGNAME=	p5-AtExit-2.01
PKGREVISION=	4
SVR4_PKGNAME=	p5ate
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AtExit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Provides an ANSI C style atexit() function to Perl programs

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/AtExit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
