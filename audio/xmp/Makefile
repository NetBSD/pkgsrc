# $NetBSD: Makefile,v 1.63 2022/07/02 16:53:08 ryoon Exp $

DISTNAME=	xmp-4.1.0
PKGREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmp/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://xmp.sourceforge.net/
COMMENT=	Player for many different Amiga and PC module formats
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes

EGDIR=		${PREFIX}/share/examples/xmp
CONF_FILES=	${EGDIR}/modules.conf ${PKG_SYSCONFDIR}/xmp/modules.conf
CONF_FILES+=	${EGDIR}/xmp.conf ${PKG_SYSCONFDIR}/xmp/xmp.conf

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${EGDIR}
INSTALL_MAKE_FLAGS+=	INSTALL=${INSTALL:Q}

.include "../../mk/bsd.prefs.mk"
.include "../../mk/oss.buildlink3.mk"

# NetBSD and Solaris have their own drivers.
.if ${OPSYS} != "NetBSD" && \
    ${OPSYS} != "SunOS" && \
    ${OSS_TYPE} != "none"
LIBS+=		${LIBOSSAUDIO}
CPPFLAGS+=	-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
CPPFLAGS+=	-DDEVOSSSOUND="\"${DEVOSSSOUND}\""
.else
CONFIGURE_ARGS+=	--disable-oss
.endif

.include "options.mk"
.include "../../audio/libxmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
