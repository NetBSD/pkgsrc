# $NetBSD: Makefile,v 1.10 2009/08/31 22:00:30 he Exp $
#

DISTNAME=	hobbit-4.2.0
PKGNAME=	hobbitclient-4.2.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hobbitmon/}

MAINTAINER=	gendalia@NetBSD.org
HOMEPAGE=	http://hobbitmon.sourceforge.net/
COMMENT=	Free-software client for the Hobbit monitor
LICENSE=	gnu-gpl-v2

PATCHFILES+=allinone.patch
SITES.allinone.patch=http://www.hobbitmon.com/hobbitsw/patches/

HAS_CONFIGURE=	YES
USE_TOOLS+=	gmake
#INSTALL_TARGET=
MAKE_JOBS_SAFE=	NO

PKG_DESTDIR_SUPPORT=destdir

.include "../../mk/bsd.prefs.mk"

BBUSER?=	hobbit
BBGROUP?=	hobbit
BBTOPDIR?=	${PREFIX}/hobbit
BBLOGDIR?=	${VARBASE}/log/hobbit
BBCLIENTLOGS?=	${VARBASE}/log/hobbit
BBTMP?=	${VARBASE}/hobbit
BBSERVERNAME?=	"`uname -n`"
BBSERVERIP?=	127.0.0.1
CONFTYPE?=	"server"
BUILD_DEFS+=	VARBASE
BUILD_DEFS+=	BBSERVERNAME
BUILD_DEFS+=	BBSERVERIP

RCD_SCRIPTS+=	hobbitclient
PKG_GROUPS=	${BBGROUP}
PKG_USERS=	${BBUSER:Q}:${BBGROUP:Q}

PKG_GECOS.${BBUSER}=	Hobbit monitor
PKG_HOME.${BBUSER}=	${BBTOPDIR}

PKG_GROUPS_VARS+=	BBGROUP
PKG_USERS_VARS+=	BBUSER

CONFIGURE_ARGS+="--client"

CONFIGURE_ENV+=	TARGET=hobbit
CONFIGURE_ENV+=	BBHOSTNAME="${BBSERVERNAME}"
CONFIGURE_ENV+=	BBUSER=${BBUSER:Q}
CONFIGURE_ENV+=	BBTOPDIR=${BBTOPDIR:Q}
CONFIGURE_ENV+=	BBLOGDIR=${BBLOGDIR:Q}
CONFIGURE_ENV+=	BBCLIENTLOGS=${BBCLIENTLOGS}
CONFIGURE_ENV+=	BBTMP=${BBTMP}
CONFIGURE_ENV+=	BBHOSTIP=${BBSERVERIP:Q}
CONFIGURE_ENV+=	MANROOT=${PREFIX}/${PKGMANDIR}/
CONFIGURE_ENV+=	CONFTYPE="${CONFTYPE}"

SUBST_CLASSES+=		BADPATHS
SUBST_STAGE.BADPATHS=	post-configure
SUBST_MESSAGE.BADPATHS=	"fixing up unfortunate BBCLIENTLOGS and BBTMP paths"
SUBST_FILES.BADPATHS=	client/runclient.sh client/hobbitclient.cfg.DIST
SUBST_FILES.BADPATHS+=	common/hobbitclient.cfg.5 client/Makefile
SUBST_FILES.BADPATHS+=	lib/environ.c client/clientlaunch.cfg.DIST
SUBST_SED.BADPATHS=	-e 's,$$(INSTALLROOT),$$(DESTDIR)$$(INSTALLROOT),g' \
			-e 's,$$HOBBITCLIENTHOME/logs,${BBCLIENTLOGS},g' \
			-e 's,$$HOBBITCLIENTHOME/tmp,${BBTMP},g' \
			-e 's,$$BBHOME/logs,${BBCLIENTLOGS},g' \
			-e 's,$$BBHOME/tmp,${BBTMP},g' \
			-e 's,$$(BBHOME)/logs,${BBCLIENTLOGS},g' \
			-e 's,$$(BBHOME)/tmp,${BBTMP},g' \
			

USE_TOOLS+=     awk:run         cat:run         cp:run
USE_TOOLS+=     cut:run         date:run        egrep:run
USE_TOOLS+=     expr:run        find:run        grep:run
USE_TOOLS+=     head:run        id:run          ls:run
USE_TOOLS+=     mv:run          rm:run          sed:run
USE_TOOLS+=     sort:run        tail:run        touch:run
USE_TOOLS+=     tr:run          wc:run

OWN_DIRS_PERMS+=	${BBTOPDIR} ${BBUSER} ${BBGROUP} 0755
OWN_DIRS_PERMS+=	${BBTOPDIR}/client ${BBUSER} ${BBGROUP} 0755
OWN_DIRS_PERMS+=	${BBTOPDIR}/client/ext ${BBUSER} ${BBGROUP} 0755
OWN_DIRS_PERMS+=	${BBCLIENTLOGS} ${BBUSER} ${BBGROUP} 0755
OWN_DIRS_PERMS+=	${BBTMP} ${BBUSER} ${BBGROUP} 0755

MAKE_ENV+=	MAKE=${MAKE_PROGRAM:Q}
MAKE_ENV+=	PKGDIR=${PREFIX:Q}
MAKE_ENV+=	${TOOLS_ENV}

.include "../../mk/bsd.pkg.mk"
