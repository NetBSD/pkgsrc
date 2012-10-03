# $NetBSD: Makefile,v 1.8 2012/10/03 21:55:04 wiz Exp $

DISTNAME=	Getopt-ArgvFile-1.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Getopt-ArgvFile/
COMMENT=	Interpolates script options from files into @ARGV or another array
LICENSE=	artistic

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Getopt/ArgvFile/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
