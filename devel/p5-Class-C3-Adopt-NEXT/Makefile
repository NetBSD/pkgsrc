# $NetBSD: Makefile,v 1.2 2009/05/17 18:28:57 sno Exp $

DISTNAME=	Class-C3-Adopt-NEXT-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-C3-Adopt-NEXT/
COMMENT=	Perl5 module to make NEXT suck less
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat

BUILD_DEPENDS+=	p5-Test-Exception>=0.27:../../devel/p5-Test-Exception

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Class/C3/Adopt/NEXT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
