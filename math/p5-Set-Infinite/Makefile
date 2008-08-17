# $NetBSD: Makefile,v 1.6 2008/08/17 17:06:25 he Exp $

DISTNAME=	Set-Infinite-0.63
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Set-Infinite/
COMMENT=	Perl module for sets of integers and objects

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Set/Infinite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
