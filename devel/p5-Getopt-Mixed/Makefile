# $NetBSD: Makefile,v 1.2 2008/06/20 01:09:16 joerg Exp $

DISTNAME=	Getopt-Mixed-1.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~rsavage/Getopt-Mixed/
COMMENT=	Mixed Getopt wrapper

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Getopt/Mixed/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
