# $NetBSD: Makefile,v 1.1.1.1 2009/04/29 19:29:51 sno Exp $

DISTNAME=	MooseX-MethodAttributes-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-MethodAttributes/
COMMENT=	Perl5 module for code attribute introspection
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-Moose>=0.70:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types>=0.06:../../devel/p5-MooseX-Types
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/MooseX/MethodAttributes/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
