# $NetBSD: Makefile,v 1.2 2018/08/21 09:55:41 wiz Exp $

DISTNAME=	Alien-Role-Alt-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/P/PL/PLICEASE/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~plicease/Alien-Role-Alt/
COMMENT=	Alien::Base role that supports alternates
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Alien-Build-[0-9]*:../../devel/p5-Alien-Build
DEPENDS+=	p5-Role-Tiny-[0-9]*:../../devel/p5-Role-Tiny
DEPENDS+=	p5-Class-Method-Modifiers-[0-9]*:../../devel/p5-Class-Method-Modifiers

PERL5_PACKLIST=         auto/Alien/Role/Alt/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
