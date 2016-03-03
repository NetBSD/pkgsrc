# $NetBSD: Makefile,v 1.49 2016/03/03 13:26:02 wiz Exp $

DISTNAME=	Math-Pari-2.010808
PKGNAME=	p5-${DISTNAME}
CATEGORIES+=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-Pari/
COMMENT=	Perl5 interface to the pari math library
LICENSE=	gnu-gpl-v2

#MAKE_PARAMS+=		paridir=${WRKDIR}/${PARI_DISTNAME}

# XXX: to use or not to use...
#DEPENDS+=		gnuplot-[0-9]*:../../graphics/gnuplot

#GCC_REQD+=		2.95
#MAKE_ENV+=		MP_NOGNUPLOT=1
MAKE_PARAMS+=		pariprefix=${PREFIX:Q}
PERL5_PACKLIST=		auto/Math/Pari/.packlist

post-extract:
	${RM} ${WRKSRC}/libPARI/Makefile.PL

BUILDLINK_API_DEPENDS.pari+=	pari>=2.3.5nb1<2.4
.include "../../math/pari23/buildlink3.mk"
MAKE_PARAMS+=		libpari=${PARI_LIB}
.if !empty(PKG_BUILD_OPTIONS.pari:Mgmp)
MAKE_PARAMS+=		addlibs="-lgmp"
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
