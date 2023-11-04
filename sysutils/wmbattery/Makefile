# $NetBSD: Makefile,v 1.3 2023/11/04 12:29:41 wiz Exp $

DISTNAME=	wmbattery-2.54
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dockapps.net/
COMMENT=	Dockapp that shows battery status
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoreconf autoconf automake gmake pkg-config

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--enable-envsys
.endif

pre-configure:
	${CP} \
	    ${FILESDIR}/envsys.c \
	    ${FILESDIR}/envsys.h \
	    ${WRKSRC}

	cd ${WRKSRC} && autoreconf -fi

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
