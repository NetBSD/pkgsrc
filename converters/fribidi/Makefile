# $NetBSD: Makefile,v 1.8 2005/07/21 16:29:45 wiz Exp $
#

DISTNAME=		fribidi-0.10.4
PKGREVISION=		1
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fribidi/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://fribidi.sourceforge.net/
COMMENT=		Free Implementation of the Unicode Bidirectional Algorithm

USE_LIBTOOL=            yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	fribidi.pc.in

TEST_TARGET=		check

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
