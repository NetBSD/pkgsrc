# $NetBSD: Makefile,v 1.12 2011/08/12 08:29:30 adam Exp $

DISTNAME=	Devel-Profile-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Profile/
COMMENT=	Perl5 module for profiling perl programs
LICENSE=	artistic

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Time-HiRes>=1.20:../../time/p5-Time-HiRes

PERL5_PACKLIST=		auto/Devel/Profile/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
