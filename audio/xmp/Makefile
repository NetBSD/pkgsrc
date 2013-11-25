# $NetBSD: Makefile,v 1.39 2013/11/25 12:00:47 wiz Exp $

DISTNAME=	xmp-4.0.6
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmp/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://xmp.sourceforge.net/
COMMENT=	Player for many different Amiga and PC module formats
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR}

USE_TOOLS+=	gmake pkg-config

EGDIR=		${PREFIX}/share/examples/xmp
CONF_FILES=	${EGDIR}/modules.conf ${PKG_SYSCONFDIR}/xmp/modules.conf
CONF_FILES+=	${EGDIR}/xmp.conf ${PKG_SYSCONFDIR}/xmp/xmp.conf

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${EGDIR}

INSTALL_MAKE_FLAGS+=	INSTALL=${INSTALL:Q}

.include "options.mk"

.include "../../audio/libxmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
