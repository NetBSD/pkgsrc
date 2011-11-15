# $NetBSD: Makefile,v 1.10 2011/11/15 12:49:16 sno Exp $

DISTNAME=	Any-Moose-0.18
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Any/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Any-Moose/
COMMENT=	Perl extension to check dependencies on Moose or Mouse
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{p5-Moose-[0-9]*,p5-Mouse>=0.40}:../../devel/p5-Mouse
BUILD_DEPENDS+=	{p5-MooseX-Types-[0-9]*,p5-MouseX-Types-[0-9]*}:../../devel/p5-MouseX-Types

PERL5_PACKLIST=	auto/Any/Moose/.packlist
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
