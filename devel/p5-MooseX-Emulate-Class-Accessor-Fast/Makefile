# $NetBSD: Makefile,v 1.1.1.1 2009/04/29 16:05:11 sno Exp $

DISTNAME=	MooseX-Emulate-Class-Accessor-Fast-0.00802
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Emulate-Class-Accessor-Fast/
COMMENT=	Emulate Class::Accessor::Fast behavior using Moose attributes
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-Moose>=0.74:../../devel/p5-Moose
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/MooseX/Emulate/Class/Accessor/Fast/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
