# $NetBSD: Makefile,v 1.33 2014/05/29 23:35:52 wiz Exp $

DISTNAME=	Expect-1.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
SVR4_PKGNAME=	p5exp
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Expect/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Expect/
COMMENT=	Perl version of the TCL "expect" tool

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-IO-Stty-[0-9]*:../../devel/p5-IO-Stty
DEPENDS+=	p5-IO-tty-[0-9]*:../../devel/p5-IO-Tty

CONFLICTS+=	p5-expect-[0-9]*

PERL5_PACKLIST=		auto/Expect/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
