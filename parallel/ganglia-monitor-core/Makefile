# $NetBSD: Makefile,v 1.89 2024/05/29 16:34:07 adam Exp $

DISTNAME=		ganglia-3.7.2
PKGNAME=		ganglia-monitor-core-3.7.2
PKGREVISION=		29
CATEGORIES=		parallel net
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
BUILD_DEFS+=		VARBASE

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
SUBST_FILES.paths=	configure ganglia.html \
			gmond/gmond.conf.5 mans/gmetric.1
SUBST_SED.paths+=	-e 's|/etc/ganglia|${PKG_SYSCONFDIR}|g'
SUBST_SED.paths+=	-e 's|/usr/lib/ganglia|${PREFIX}/lib/ganglia|g'
SUBST_VARS.paths+=	GANGLIA_VARBASE

## gmond.conf.5 and gmond.conf.html can be generated from conf.pod, but
## doing so requires perl installed in the build stage.
SUBST_CLASSES+=		etcdir
SUBST_STAGE.etcdir=	pre-configure
SUBST_FILES.etcdir+=	README
SUBST_FILES.etcdir+=	mans/gmetad.1
SUBST_FILES.etcdir+=	mans/gmond.1
SUBST_SED.etcdir=	-e "s|/etc/ganglia/\(gm.*d\.conf\)|${PREFIX}/etc/\1|g"

SUBST_CLASSES+=			linux_init
SUBST_STAGE.linux_init=		pre-configure
SUBST_FILES.linux_init=		gmond/gmond.init
SUBST_FILES.linux_init+=	gmetad/gmetad.init
SUBST_SED.linux_init=		-e 's|/usr/sbin|${PREFIX}/sbin|g'
SUBST_SED.linux_init+=		-e 's|/etc/sysconfig|${PREFIX}&|g'
SUBST_SED.linux_init+=		-e 's|/etc/ganglia|${PREFIX}&|g'
SUBST_SED.linux_init+=		-e 's|/var/lock/subsys|${PREFIX}&|g'

SUBST_CLASSES+=		systemd
SUBST_STAGE.systemd=	pre-configure
SUBST_FILES.systemd=	gmond/gmond.service gmetad/gmetad.service
SUBST_SED.systemd=	-e 's|@runstatedir@|${PREFIX}/var/run|g'
SUBST_SED.systemd+=	-e 's|@sbindir@|${PREFIX}/sbin|g'

FILES_SUBST+=		GANGLIA_VARBASE=${GANGLIA_VARBASE}

DOCDIR=			${PREFIX}/share/doc/ganglia
EGDIR=			${PREFIX}/share/examples/ganglia
CONF_FILES=		${EGDIR}/gmond.conf ${PKG_SYSCONFDIR}/gmond.conf
CONF_FILES+=		${EGDIR}/gmetad.conf ${PKG_SYSCONFDIR}/gmetad.conf

RCD_SCRIPTS=		gmond gmetad
SMF_NAME=		ganglia
SMF_INSTANCES=		${RCD_SCRIPTS}

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR} ${PKGMANDIR}/man1 ${PKGMANDIR}/man5
INSTALLATION_DIRS+=	var/lock/subsys

post-extract:
	${CP} ${FILESDIR}/gmond.service.in ${WRKSRC}/gmond/gmond.service
	${CP} ${FILESDIR}/gmetad.service.in ${WRKSRC}/gmetad/gmetad.service

post-install:
	${WRKSRC}/gmond/gmond -t > ${DESTDIR}${EGDIR}/gmond.conf
	${INSTALL_DATA} ${WRKSRC}/gmond/modules/python/README \
		${DESTDIR}${DOCDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/gmond/gmond.init \
		${DESTDIR}${EGDIR}/gmond.init.linux
	${INSTALL_SCRIPT} ${WRKSRC}/gmond/gmond.service \
		${DESTDIR}${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/gmetad/gmetad.init \
		${DESTDIR}${EGDIR}/gmetad.init.linux
	${INSTALL_SCRIPT} ${WRKSRC}/gmetad/gmetad.service \
		${DESTDIR}${EGDIR}

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../devel/apr/buildlink3.mk"
.include "../../devel/confuse/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
