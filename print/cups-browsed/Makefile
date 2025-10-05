# $NetBSD: Makefile,v 1.3 2025/10/05 19:26:14 js Exp $

DISTNAME=	cups-browsed-2.1.1
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenPrinting/}
GITHUB_PROJECT=	cups-browsed
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/OpenPrinting/cups-browsed
COMMENT=	Helper daemon to browse the network for remote CUPS queues and IPP printers
LICENSE=	apache-2.0 # with gnu-gpl-v2 and gnu-lgpl-v2 exception

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gdbus-codegen pkg-config

RCD_SCRIPTS=	cups-browsed
CONF_FILES+=	${PREFIX}/share/examples/cups-filters/cups-browsed.conf ${PKG_SYSCONFDIR}/cups/cups-browsed.conf

.include "options.mk"

INSTALLATION_DIRS+=	share/examples/cups-filters

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/cups/cups-browsed.conf \
		${DESTDIR}${PREFIX}/share/examples/cups-filters/cups-browsed.conf

.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../print/libcupsfilters/buildlink3.mk"
.include "../../print/libppd/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
