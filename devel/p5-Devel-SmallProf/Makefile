# $NetBSD: Makefile,v 1.22 2008/10/19 19:17:52 he Exp $
#

DISTNAME=		Devel-SmallProf-2.02
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5dsp
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=		bad@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~salva/Devel-SmallProf-1.15/
COMMENT=		Perl5 module for line-by-line profiling perl programs

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Time-HiRes>=1.20:../../time/p5-Time-HiRes

PERL5_PACKLIST=		auto/Devel/SmallProf/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
