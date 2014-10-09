# $NetBSD: Makefile,v 1.29 2014/10/09 13:44:33 wiz Exp $
#

.include "../../converters/nkf/Makefile.common"

PKGNAME=	p5-nkf-2.13
PKGREVISION=	1
CATEGORIES=	japanese converters perl5

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Perl library for Network Kanji code conversion Filter
#LICENSE=	zlib-license

USE_LANGUAGES=	c

PERL5_CONFIGURE_DIRS=	NKF.mod
BUILD_DIRS=		${PERL5_CONFIGURE_DIRS}
PERL5_PACKLIST=		auto/NKF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
