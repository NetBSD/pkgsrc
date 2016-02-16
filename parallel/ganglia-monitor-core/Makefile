# $NetBSD: Makefile,v 1.54 2016/02/16 12:48:18 fhajny Exp $
#

DISTNAME=		ganglia-3.7.2
PKGNAME=		ganglia-monitor-core-3.7.2
CATEGORIES=		net parallel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ganglia/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ganglia.sourceforge.net/
COMMENT=		Ganglia cluster monitor, monitoring daemon
LICENSE=		modified-bsd

GNU_CONFIGURE=		yes
SET_LIBDIR=		yes

USE_LIBTOOL=		yes
USE_LANGUAGES=		c c99
USE_TOOLS+=		pkg-config

PLIST_VARS+=		python

PKG_OPTIONS_VAR=	PKG_OPTIONS.ganglia
PKG_SUPPORTED_OPTIONS=	python		# Gmond support for python modules

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-gmetad
CONFIGURE_ARGS+=	--enable-setuid=${GANGLIA_USER}
CONFIGURE_ARGS+=	--enable-setgid=${GANGLIA_GROUP}

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}
PLIST.python=		yes
CONF_FILES+=		${EGDIR}/conf.d/modpython.conf \
			${PKG_SYSCONFDIR}/gmond.conf.d/modpython.conf
.include "../../lang/python/application.mk"
.else
CONFIGURE_ARGS+=	--disable-python
.endif

GANGLIA_USER?=			ganglia
GANGLIA_GROUP?=			${GANGLIA_USER}
GANGLIA_VARBASE?=		${VARBASE}/db

PKG_GROUPS+=			${GANGLIA_GROUP}
PKG_USERS+=			${GANGLIA_USER}:${GANGLIA_GROUP}
PKG_GECOS.${GANGLIA_USER}=	Ganglia daemon user
PKG_HOME.${GANGLIA_USER}=	${GANGLIA_VARBASE}/ganglia

OWN_DIRS_PERMS+=		${GANGLIA_VARBASE}/ganglia ${GANGLIA_USER} ${GANGLIA_GROUP} 0755
OWN_DIRS_PERMS+=		${GANGLIA_VARBASE}/ganglia/rrds ${GANGLIA_USER} ${GANGLIA_GROUP} 0755

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing default paths
SUBST_FILES.paths=	configure ganglia.html			\
			gmetad/cmdline.c gmetad/cmdline.h	\
			gmetric/cmdline.c gmetric/cmdline.h	\
			gmond/cmdline.c gmond/cmdline.h		\
			gmond/g25_config.h gmond/gmond.conf.5	\
			gmond/modules/conf.d/modpython.conf	\
			gmond/modules/conf.d/modpython.conf.in	\
			gmond/modules/python/README.in		\
			mans/gmetad.1 mans/gmetric.1 mans/gmond.1
SUBST_SED.paths+=	-e 's,/etc/ganglia,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,/usr/lib/ganglia,${PREFIX}/lib/ganglia,g'
SUBST_VARS.paths+=	GANGLIA_VARBASE

FILES_SUBST+=		GANGLIA_VARBASE=${GANGLIA_VARBASE}

DOCDIR=			${PREFIX}/share/doc/ganglia
EGDIR=			${PREFIX}/share/examples/ganglia
CONF_FILES=		${EGDIR}/gmond.conf ${PKG_SYSCONFDIR}/gmond.conf
CONF_FILES+=		${EGDIR}/gmetad.conf ${PKG_SYSCONFDIR}/gmetad.conf

RCD_SCRIPTS=		gmond gmetad
SMF_NAME=		ganglia
SMF_INSTANCES=		${RCD_SCRIPTS}

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR} ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

post-install:
	${WRKSRC}/gmond/gmond -t > ${DESTDIR}${EGDIR}/gmond.conf
	${INSTALL_DATA} ${WRKSRC}/gmond/modules/python/README ${DESTDIR}${DOCDIR}/

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../devel/apr/buildlink3.mk"
.include "../../devel/confuse/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
