# $NetBSD: Makefile,v 1.23 2013/03/21 06:53:36 sbd Exp $
#

DISTNAME=	openobex-1.7-Source
PKGNAME=	openobex-1.7
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openobex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitorious.org/openobex
COMMENT=	Implementation of the Object Exchange (OBEX) protocol
LICENSE=	gnu-lgpl-v2

BUILD_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen

USE_CMAKE=	yes
USE_TOOLS+=	cmake pkg-config

PKGCONFIG_OVERRIDE=	openobex.pc.in

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

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
