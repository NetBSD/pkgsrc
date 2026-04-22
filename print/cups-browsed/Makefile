# $NetBSD: Makefile,v 1.8 2026/04/22 17:24:19 wiz Exp $

DISTNAME=	cups-browsed-2.1.1
PKGREVISION=	7
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

post-extract:
	${CP} ${FILESDIR}/cups-browsed-daemonize.sh ${WRKSRC}

SUBST_CLASSES+=			daemonize
SUBST_STAGE.daemonize=		pre-configure
SUBST_MESSAGE.daemonize=	Customizing daemonizing script
SUBST_FILES.daemonize=		cups-browsed-daemonize.sh
SUBST_VARS.daemonize=		PREFIX VARBASE

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/cups/cups-browsed.conf \
		${DESTDIR}${PREFIX}/share/examples/cups-filters/cups-browsed.conf
	${INSTALL_SCRIPT} ${WRKSRC}/cups-browsed-daemonize.sh ${DESTDIR}${PREFIX}/libexec/cups-browsed

.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../print/libcupsfilters/buildlink3.mk"
.include "../../print/libppd/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
