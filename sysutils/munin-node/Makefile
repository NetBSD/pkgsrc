# $NetBSD: Makefile,v 1.39 2019/08/11 13:23:10 wiz Exp $
#

DISTNAME=	munin_${VER}
VER=		1.3.2
PKGNAME=	munin-node-${VER}
PKGREVISION=	22
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=munin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://munin-monitoring.org/
COMMENT=	System monitoring tool, client version

PKG_DESTDIR_SUPPORT=	destdir

USERGROUP_PHASE=	pre-install

DEPENDS+=	p5-Net-Server>=0:../../net/p5-Net-Server
DEPENDS+=	p5-Net-SSLeay>=0:../../security/p5-Net-SSLeay
DEPENDS+=	munin-doc>=1.3.1:../../sysutils/munin-doc

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	perl:run tar
USE_TOOLS+=	gmake
USE_PKGINSTALL=	YES

WRKSRC=		${WRKDIR}/${DISTNAME:S:_:-:}

PLIST_VARS+=	sunos not-sunos netbsd not-netbsd linux not-linux

.if ${OPSYS} == "Linux"
PLIST.linux=	yes
.else
PLIST.not-linux= yes
.endif

.if ${OPSYS} == "NetBSD"
PLIST.netbsd=	yes
.else
PLIST.not-netbsd= yes
.endif

.if ${OPSYS} == "SunOS"
PLIST.sunos=	yes
.else
PLIST.not-sunos= yes
.endif

PKG_GROUPS_VARS+=	MUNIN_GROUP
PKG_USERS_VARS+=	MUNIN_USER

MUNIN_GROUP?=	munin
MUNIN_USER?=	munin

PKG_GROUPS=	${MUNIN_GROUP}
PKG_USERS=	${MUNIN_USER}:${MUNIN_GROUP}
PKG_GECOS.${MUNIN_USER}=	Munin user
PKG_SYSCONFSUBDIR?=	munin
REPLACE_PERL+=	node/node.d/*.in

STATEDIR?=	${VARBASE}/munin/plugin-state
MUNIN_RUN?=	${VARBASE}/run/munin

MAKE_DIRS+=	${PKG_SYSCONFDIR}/plugins

OWN_DIRS+=	${VARBASE}/munin
OWN_DIRS+=	${MUNIN_RUN}
OWN_DIRS+=	${VARBASE}/log/munin
OWN_DIRS+=	${STATEDIR}

OWN_DIRS_PERMS+=${VARBASE}/munin ${MUNIN_USER} ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=${MUNIN_RUN} ${MUNIN_USER} ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=${VARBASE}/log/munin ${MUNIN_USER} ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=${STATEDIR} ${MUNIN_USER} ${MUNIN_GROUP} 0775

INSTALL_TARGET=	install-node install-node-plugins

BUILD_TARGET=	build

#MAKE_ENV+=	PERL5_SITELIB=${PERL5_SITELIB}
MAKE_ENV+=	PREFIX=${PREFIX}
MAKE_ENV+=	CONFDIR=${PKG_SYSCONFDIR}
MAKE_ENV+=	MUNIN_USER=${MUNIN_USER}
MAKE_ENV+=	MUNIN_GROUP=${MUNIN_GROUP}
MAKE_ENV+=	PERL5=${PERL5:Q}
MAKE_ENV+=	PYTHONBIN=${PYTHONBIN:Q}

FILES_SUBST+=	PERL=${PERL5:Q}
FILES_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
FILES_SUBST+=	STATEDIR=${STATEDIR}
FILES_SUBST+=	MUNIN_RUN=${MUNIN_RUN:Q}
FILES_SUBST+=	MUNIN_USER=${MUNIN_USER:Q}
FILES_SUBST+=	MUNIN_GROUP=${MUNIN_GROUP:Q}

MESSAGE_SUBST+=	VARBASE=${VARBASE:Q}

BUILD_DEFS+=	VARBASE

RCD_SCRIPTS+=	munin-node
SMF_NAME=	munin

EGDIR=		${PREFIX}/share/examples/munin

CONF_FILES+=	${EGDIR}/munin-node.conf ${PKG_SYSCONFDIR}/munin-node.conf
INSTALLATION_DIRS+=	${EGDIR}

pre-configure:
	cd ${FILESDIR}; ${TAR} cf - . | (cd ${WRKSRC}; ${TAR} xfp -)

post-install:
	${INSTALL_DATA} ${WRKSRC}/build/node/munin-node.conf ${DESTDIR}${EGDIR}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
