# $NetBSD: Makefile,v 1.16 2006/02/05 23:08:50 joerg Exp $
#

DISTNAME=	gettext-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5gtx
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/gettext/
COMMENT=	Perl5 module interface to C I18N functions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Locale/gettext/.packlist

SUBST_CLASSES+=		intlpath
SUBST_FILES.intlpath=	Makefile.PL
SUBST_SED.intlpath+=	-e 's,-lintl,-L${BUILDLINK_PREFIX.gettext}/lib -lintl,g'
SUBST_STAGE.intlpath=	pre-configure

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
