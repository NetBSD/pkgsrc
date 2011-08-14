# $NetBSD: Makefile,v 1.5 2011/08/14 12:26:07 obache Exp $

DISTNAME=	Getopt-Mixed-1.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~rsavage/Getopt-Mixed/
COMMENT=	Mixed Getopt wrapper

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Getopt/Mixed/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
