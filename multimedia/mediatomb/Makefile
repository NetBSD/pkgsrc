# $NetBSD: Makefile,v 1.9 2009/06/12 17:24:53 ahoka Exp $

DISTNAME=	mediatomb-0.11.0
PKGREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mediatomb/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://mediatomb.cc/
COMMENT=	UPnP MediaServer with a web user interface

GNU_CONFIGURE=	yes

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config automake autoconf autoreconf
USE_DIRS+=	xdg-1.4

RCD_SCRIPTS=	mediatomb

.include "../../mk/bsd.prefs.mk"

PKG_GROUPS=			${MEDIATOMB_GROUP}
PKG_USERS=			${MEDIATOMB_USER}:${MEDIATOMB_GROUP}

PKG_GECOS.${MEDIATOMB_USER}=	MediaTomb Server
PKG_HOME.${MEDIATOMB_USER}=	${VARBASE}/mediatomb

PKG_SYSCONFSUBDIR=	mediatomb
EGDIR=			${PREFIX}/share/examples/mediatomb
CONF_FILES_PERMS+=	${EGDIR}/config.xml ${PKG_SYSCONFDIR}/config.xml \
			${MEDIATOMB_USER} ${MEDIATOMB_GROUP} 0644

FILES_SUBST+=			PKG_HOME=${PKG_HOME.${MEDIATOMB_USER}:Q}
FILES_SUBST+=			MEDIATOMB_GROUP=${MEDIATOMB_GROUP:Q}
FILES_SUBST+=			MEDIATOMB_USER=${MEDIATOMB_USER:Q}
FILES_SUBST+=			PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

MEDIATOMB_HOME=		${PKG_HOME.${MEDIATOMB_USER}}

SUBST_CLASSES+=		config
SUBST_FILES.config=	config.xml mediatomb.desktop
SUBST_VARS.config=	MEDIATOMB_HOME PREFIX OPSYS
SUBST_STAGE.config=	post-patch

post-extract:
	${CP} ${FILESDIR}/config.xml.in ${WRKSRC}/config.xml
	${CP} ${FILESDIR}/mediatomb.desktop.in ${WRKSRC}/mediatomb.desktop

pre-configure:
	cd ${WRKSRC} && autoreconf -i

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/config.xml ${EGDIR}/config.xml
	${INSTALL_DATA} ${WRKSRC}/mediatomb.desktop ${PREFIX}/share/applications/mediatomb.desktop

PREFER.bind=	pkgsrc	# we need the package for the lwres lib

.include "options.mk"

.include "../../audio/taglib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../net/bind9/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
