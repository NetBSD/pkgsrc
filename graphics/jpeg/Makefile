# $NetBSD: Makefile,v 1.19 2002/08/25 18:39:13 jlam Exp $
#

DISTNAME=		jpegsrc.v6b
PKGNAME=		jpeg-6b
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.uu.net/graphics/jpeg/

MAINTAINER=		mycroft@netbsd.org
HOMEPAGE=		http://www.ijg.org/
COMMENT=		IJG's jpeg compression utilities

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-static
INSTALL_TARGET=		install install-lib

.include "../../mk/bsd.pkg.mk"
