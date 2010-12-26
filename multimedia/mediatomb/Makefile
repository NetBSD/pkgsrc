# $NetBSD: Makefile,v 1.18 2010/12/26 22:33:33 tron Exp $

DISTNAME=	mediatomb-0.12.1
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mediatomb/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://mediatomb.cc/
COMMENT=	UPnP MediaServer with a web user interface
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config automake autoconf autoreconf

RCD_SCRIPTS=	mediatomb

.include "../../mk/bsd.prefs.mk"

PKG_GROUPS=			${MEDIATOMB_GROUP}
PKG_USERS=			${MEDIATOMB_USER}:${MEDIATOMB_GROUP}

PKG_GECOS.${MEDIATOMB_USER}=	MediaTomb Server
PKG_HOME.${MEDIATOMB_USER}=	${VARBASE}/mediatomb

PKG_SYSCONFSUBDIR=	mediatomb
EGDIR=			${PREFIX}/share/examples/mediatomb
CONF_FILES_PERMS+=	${EGDIR}/config.xml ${PKG_SYSCONFDIR}/config.xml \
			${MEDIATOMB_USER} ${MEDIATOMB_GROUP} 0640

FILES_SUBST+=			PKG_HOME=${PKG_HOME.${MEDIATOMB_USER}:Q}
FILES_SUBST+=			MEDIATOMB_GROUP=${MEDIATOMB_GROUP:Q}
FILES_SUBST+=			MEDIATOMB_USER=${MEDIATOMB_USER:Q}
FILES_SUBST+=			PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

MEDIATOMB_HOME=		${PKG_HOME.${MEDIATOMB_USER}}

SUBST_CLASSES+=		config
SUBST_FILES.config=	config.xml mediatomb.desktop
SUBST_VARS.config=	MEDIATOMB_HOME PREFIX OPSYS
SUBST_STAGE.config=	post-patch

INSTALLATION_DIRS+=	share/applications share/examples/mediatomb

post-extract:
	${CP} ${FILESDIR}/config.xml.in ${WRKSRC}/config.xml
	${CP} ${FILESDIR}/mediatomb.desktop.in ${WRKSRC}/mediatomb.desktop

pre-configure:
	cd ${WRKSRC} && autoreconf -i

post-install:
	${INSTALL_DATA} ${WRKSRC}/config.xml ${DESTDIR}${EGDIR}/config.xml
	${INSTALL_DATA} ${WRKSRC}/mediatomb.desktop \
		${DESTDIR}${PREFIX}/share/applications/mediatomb.desktop

.include "options.mk"

.include "../../audio/taglib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.if ${OPSYS} == "NetBSD"
PREFER.bind=	pkgsrc	# we need the package for the lwres lib
.include "../../net/bind95/buildlink3.mk"
.endif
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
