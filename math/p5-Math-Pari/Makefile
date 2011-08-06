# $NetBSD: Makefile,v 1.41 2011/08/06 20:49:25 adam Exp $

DISTNAME=	Math-Pari-2.01080605
PKGNAME=	p5-${DISTNAME:S/01080605/010806.05/}
SVR4_PKGNAME=	p5mpa
CATEGORIES+=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-Pari/
COMMENT=	Perl5 interface to the pari math library
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
#MAKE_PARAMS+=		paridir=${WRKDIR}/${PARI_DISTNAME}

# XXX: to use or not to use...
#DEPENDS+=		gnuplot-[0-9]*:../../graphics/gnuplot

#GCC_REQD+=		2.95
#MAKE_ENV+=		MP_NOGNUPLOT=1
MAKE_PARAMS+=		pariprefix=${PREFIX:Q}
PERL5_PACKLIST=		auto/Math/Pari/.packlist

post-extract:
	${RM} ${WRKSRC}/libPARI/Makefile.PL

BUILDLINK_API_DEPENDS.pari+=	pari>=2.3.5nb1
.include "../../math/pari/buildlink3.mk"
MAKE_PARAMS+=		libpari=${PARI_LIB}
.if !empty(PKG_BUILD_OPTIONS.pari:Mgmp)
MAKE_PARAMS+=		addlibs="-lgmp"
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
