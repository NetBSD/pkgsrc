# $NetBSD: Makefile,v 1.23 2009/06/30 00:07:10 joerg Exp $

DISTNAME=	xmp-2.5.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmp/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://xmp.sourceforge.net/
COMMENT=	Player for many different Amiga and PC module formats

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-alsa \
		--disable-oss \
		--disable-xmms \
		--sysconfdir=${PKG_SYSCONFDIR}

USE_TOOLS+=	gmake pkg-config

EGDIR=		${PREFIX}/share/examples/xmp
CONF_FILES=	${EGDIR}/xmp-modules.conf ${PKG_SYSCONFDIR}/xmp-modules.conf
CONF_FILES+=	${EGDIR}/xmp.conf ${PKG_SYSCONFDIR}/xmp.conf

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${EGDIR}

INSTALL_MAKE_FLAGS+=	INSTALL=${INSTALL}

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" || ${OPSYS} == "Interix"
# No native support for these OS's, so use esound for audio output
.include "../../audio/esound/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
