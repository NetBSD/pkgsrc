# $NetBSD: Makefile,v 1.59 2022/08/02 07:22:00 ast Exp $

DISTNAME=	Math-Pari-2.030523
PKGREVISION=	1
CATEGORIES+=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Math-Pari
COMMENT=	Perl5 interface to the pari math library
LICENSE=	gnu-gpl-v2

#MAKE_PARAMS+=		paridir=${WRKDIR}/${PARI_DISTNAME}

# XXX: to use or not to use...
#DEPENDS+=		gnuplot-[0-9]*:../../graphics/gnuplot

#GCC_REQD+=		2.95
#MAKE_ENV+=		MP_NOGNUPLOT=1
MAKE_PARAMS+=		pariprefix=${PREFIX:Q}
PERL5_PACKLIST=		auto/Math/Pari/.packlist
CFLAGS.NetBSD+=		-DUSE_STANDALONE_PARILIB=1

post-extract:
	${RM} ${WRKSRC}/libPARI/Makefile.PL

BUILDLINK_API_DEPENDS.pari+=	pari>=2.3.5nb1<2.4
.include "../../math/pari23/buildlink3.mk"
MAKE_PARAMS+=		libpari=${PARI_LIB}
.if ${PKG_BUILD_OPTIONS.pari:Mgmp}
MAKE_PARAMS+=		addlibs="-lgmp"
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
