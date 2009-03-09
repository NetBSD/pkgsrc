# $NetBSD: Makefile,v 1.1.1.1 2009/03/09 19:40:59 rhaen Exp $
#

DISTNAME=	Any-Moose-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/F/FL/FLORA/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Any-Moose/
COMMENT=	Perl extension to check dependencies on Moose or Mouse

DEPENDS+=	p5-Mouse>=0.15:../../devel/p5-Mouse

PERL5_PACKLIST=	auto/Any/Moose/.packlist
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
