# $NetBSD: Makefile,v 1.1.1.1 2003/12/14 01:16:39 xtraeme Exp $
#

DISTNAME=		fribidi-0.10.4
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fribidi/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://fribidi.sourceforge.net/
COMMENT=		Free Implementation of the Unicode Bidirectional Algorithm

USE_BUILDLINK2=		yes
USE_LIBTOOL=            yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/fribidi.pc.in

TEST_TARGET=		check

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
