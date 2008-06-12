# $NetBSD: Makefile,v 1.14 2008/06/12 02:14:36 joerg Exp $

DISTNAME=	Math-MatrixReal-2.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mmr
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-MatrixReal/
COMMENT=	Perl module for performing operations on real matrices

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Math/MatrixReal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
