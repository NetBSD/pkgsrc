# $NetBSD: Makefile,v 1.25 2008/02/09 16:36:44 rhaen Exp $

DISTNAME=	Expect-1.21
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5exp
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Expect/}

MAINTAINER=	rhaen@NetBSD.org
COMMENT=	Perl version of the TCL "expect" tool

DEPENDS+=	p5-IO-stty-[0-9]*:../../devel/p5-IO-Stty
DEPENDS+=	p5-IO-tty-[0-9]*:../../devel/p5-IO-Tty

CONFLICTS+=	p5-expect-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Expect/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
