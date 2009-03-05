# $NetBSD: Makefile,v 1.34 2009/03/05 23:12:51 seb Exp $
#

DISTNAME=		Math-Pari-2.010801
PKGREVISION=		1
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5mpa
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Math/}

DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			pari-2.1.6.tgz

#SITES.pari-2.1.6.tgz=	http://pari.math.u-bordeaux.fr/pub/pari/unix/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Math-Pari/
COMMENT=		Perl5 interface to the pari math library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		perl

# XXX: to use or not to use...
#DEPENDS+=		gnuplot-[0-9]*:../../graphics/gnuplot

GCC_REQD+=		2.95
MAKE_ENV+=		MP_NOGNUPLOT=1
PERL5_PACKLIST=		auto/Math/Pari/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
