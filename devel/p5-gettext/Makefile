# $NetBSD: Makefile,v 1.42 2024/03/31 14:41:20 js Exp $

DISTNAME=	gettext-1.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/gettext
COMMENT=	Perl5 module interface to C I18N functions
LICENSE=	${PERL5_LICENSE}
WRKSRC=		${WRKDIR}/Locale-${DISTNAME}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Locale/gettext/.packlist

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		intlpath
SUBST_FILES.intlpath=	Makefile.PL
.if ${OPSYS} == "QNX"
SUBST_SED.intlpath+=	-e 's,-lintl,-L${BUILDLINK_PREFIX.gettext}/lib -lintl -liconv,g'
.else
SUBST_SED.intlpath+=	-e 's,-lintl,-L${BUILDLINK_PREFIX.gettext}/lib -lintl,g'
.endif
SUBST_STAGE.intlpath=	pre-configure

.if ${OPSYS} == "QNX"
.include "../../converters/libiconv/buildlink3.mk"
.endif
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
