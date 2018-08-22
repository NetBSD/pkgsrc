# $NetBSD: Makefile,v 1.16 2018/08/22 09:45:48 wiz Exp $

DISTNAME=		gmediaserver-0.13.0
PKGREVISION=		12
CATEGORIES=		multimedia net
MASTER_SITES=		http://download.savannah.gnu.org/releases/gmediaserver/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gmediaserver/
COMMENT=		UPnP compatible media server for the GNU system
LICENSE=		gnu-gpl-v3

USE_TOOLS+=		perl pkg-config gmake makeinfo msgfmt
GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--with-id3lib=${BUILDLINK_PREFIX.id3lib}
CONFIGURE_ARGS+=	--with-libupnp=${BUILDLINK_PREFIX.libupnp}

EGDIR=			share/examples/gmediaserver
CFGNAME=		gmediaserver.conf
CFGFILE=		${PKG_SYSCONFDIR}/${CFGNAME}

CONF_FILES=		${PREFIX}/${EGDIR}/${CFGNAME} ${CFGFILE}
INSTALLATION_DIRS+=	${EGDIR}
OWN_DIRS_PERMS+= 	${VARBASE}/gmediaserver ${GMEDIA_USER} \
			${GMEDIA_GROUP} 750
RCD_SCRIPTS=		gmediaserver

GMEDIA_USER?=			gmedia
GMEDIA_GROUP?=			gmedia

PKG_GROUPS_VARS+=		GMEDIA_GROUP
PKG_USERS_VARS+=		GMEDIA_USER

PKG_GROUPS=			${GMEDIA_GROUP}
PKG_USERS=			${GMEDIA_USER}:${GMEDIA_GROUP}
PKG_GECOS.${GMEDIA_USER}=	GMediaServer pseudo-user
PKG_SHELL.${GMEDIA_USER}=	${SH}

BUILD_DEFS+=	VARBASE
FILES_SUBST+=	CFGFILE=${CFGFILE:Q}
FILES_SUBST+=	GMEDIA_GROUP=${GMEDIA_GROUP:Q} GMEDIA_USER=${GMEDIA_USER:Q}

post-install:
	${INSTALL_DATA} ${FILESDIR}/${CFGNAME} ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../net/libupnp/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
