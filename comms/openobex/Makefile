# $NetBSD: Makefile,v 1.37 2023/06/06 12:40:24 riastradh Exp $

DISTNAME=	openobex-1.7.2-Source
PKGNAME=	${DISTNAME:C/-Source//}
PKGREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openobex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://gitorious.org/openobex
COMMENT=	Implementation of the Object Exchange (OBEX) protocol
LICENSE=	gnu-lgpl-v2

TOOL_DEPENDS+=	doxygen>=1.9.7:../../devel/doxygen

USE_CMAKE=	yes
USE_TOOLS+=	cmake pkg-config

PKGCONFIG_OVERRIDE=	openobex.pc.in

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.prefs.mk"

EGDIR=		share/examples/openobex

.if ${OPSYS} == "Linux"
INSTALLATION_DIRS+=	${EGDIR}
MAKE_DIRS+=		/etc/udev /etc/udev/rules.d
CONF_FILES+=		${EGDIR}/60-openobex.rules \
			/etc/udev/rules.d/60-openobex.rules

post-install:
	${MV} ${DESTDIR}/lib/udev/rules.d/60-openobex.rules \
	      ${DESTDIR}${PREFIX}/${EGDIR}/60-openobex.rules
.endif

.include "../../mk/libusb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
