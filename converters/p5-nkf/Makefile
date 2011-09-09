# $NetBSD: Makefile,v 1.23 2011/09/09 11:01:17 obache Exp $
#

.include "../../converters/nkf/Makefile.common"

PKGNAME=	p5-nkf-2.12
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

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
