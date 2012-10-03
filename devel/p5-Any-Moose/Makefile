# $NetBSD: Makefile,v 1.11 2012/10/03 21:54:35 wiz Exp $

DISTNAME=	Any-Moose-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
