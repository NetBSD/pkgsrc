# $NetBSD: Makefile,v 1.23 2019/09/21 21:34:44 nia Exp $

.include "../../graphics/openexr/Makefile.common"

PKGNAME=	${DISTNAME:S/openexr/ilmbase/}

CONFIGURE_DIRS=	IlmBase
BUILD_DIRS=	IlmBase

PKGCONFIG_OVERRIDE=	IlmBase.pc.in

CONFLICTS=		openexr<1.6

pre-configure:
	cd ${WRKSRC}/IlmBase && ./bootstrap

.include "../../mk/bsd.pkg.mk"
