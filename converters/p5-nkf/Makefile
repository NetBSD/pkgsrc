# $NetBSD: Makefile,v 1.18 2009/11/19 05:42:02 obache Exp $
#

.include "../../converters/nkf/Makefile.common"

PKGNAME=	p5-nkf-2.10
SVR4_PKGNAME=	p5nkf
CATEGORIES=	japanese converters perl5

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Perl library for Network Kanji code conversion Filter
#LICENSE=	zlib-license

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c

PERL5_CONFIGURE_DIRS=	NKF.mod
BUILD_DIRS=		${PERL5_CONFIGURE_DIRS}
PERL5_PACKLIST=		auto/NKF/.packlist

SUBST_CLASSES+=		sp
SUBST_STAGE.sp=		pre-configure
SUBST_FILES.sp=		nkf.c
SUBST_SED.sp=		-e 's/SP/SPSP/g'

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
