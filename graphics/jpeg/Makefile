# $NetBSD: Makefile,v 1.24 2003/09/05 18:53:30 tron Exp $
#

DISTNAME=		jpegsrc.v6b
PKGNAME=		jpeg-6b
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.fu-berlin.de/unix/graphics/jpeg/ \
			ftp://ftp.uu.net/graphics/jpeg/

MAINTAINER=		mycroft@NetBSD.org
HOMEPAGE=		http://www.ijg.org/
COMMENT=		IJG's jpeg compression utilities

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-static
INSTALL_TARGET=		install install-lib

.include "../../mk/bsd.pkg.mk"
