# $NetBSD: Makefile,v 1.5 2004/05/07 01:14:47 xtraeme Exp $
#

DISTNAME=		fribidi-0.10.4
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fribidi/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://fribidi.sourceforge.net/
COMMENT=		Free Implementation of the Unicode Bidirectional Algorithm

USE_BUILDLINK3=		yes
USE_LIBTOOL=            yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	fribidi.pc.in

TEST_TARGET=		check

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
