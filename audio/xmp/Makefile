# $NetBSD: Makefile,v 1.35 2012/10/02 23:48:16 asau Exp $

DISTNAME=	xmp-3.4.1
PKGREVISION=	5
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

.include "../../mk/bsd.pkg.mk"
