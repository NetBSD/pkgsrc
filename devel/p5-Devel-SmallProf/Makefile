# $NetBSD: Makefile,v 1.23 2010/08/21 16:33:37 seb Exp $
#

DISTNAME=		Devel-SmallProf-2.02
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
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
