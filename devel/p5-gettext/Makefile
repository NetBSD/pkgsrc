# $NetBSD: Makefile,v 1.31 2015/06/12 10:49:57 wiz Exp $

DISTNAME=	gettext-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/gettext/
COMMENT=	Perl5 module interface to C I18N functions
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Locale/gettext/.packlist

SUBST_CLASSES+=		intlpath
SUBST_FILES.intlpath=	Makefile.PL
SUBST_SED.intlpath+=	-e 's,-lintl,-L${BUILDLINK_PREFIX.gettext}/lib -lintl,g'
SUBST_STAGE.intlpath=	pre-configure

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
