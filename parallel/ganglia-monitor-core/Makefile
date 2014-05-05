# $NetBSD: Makefile,v 1.52 2014/05/05 00:48:16 ryoon Exp $
#

DISTNAME=		ganglia-3.1.2
PKGNAME=		ganglia-monitor-core-3.1.2
PKGREVISION=		24
CATEGORIES=		net parallel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ganglia/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ganglia.sourceforge.net/
COMMENT=		Ganglia cluster monitor, monitoring daemon

GNU_CONFIGURE=		yes
SET_LIBDIR=		yes

CONFIGURE_ARGS+=	--with-gmetad
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++ c99

PLIST_VARS+=		python

PKG_OPTIONS_VAR=	PKG_OPTIONS.ganglia
PKG_SUPPORTED_OPTIONS=	python		# Gmond support for python modules

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}
PLIST.python=		yes
.include "../../lang/python/application.mk"
.else
CONFIGURE_ARGS+=	--disable-python
.endif

SUBST_CLASSES+=		pkg_sysconfdir
SUBST_STAGE.pkg_sysconfdir=	pre-configure
SUBST_MESSAGE.pkg_sysconfdir=	Fixing PKG_SYSCONFDIR
SUBST_FILES.pkg_sysconfdir=	ganglia.html				\
				gmetad/cmdline.c gmetad/cmdline.h	\
				gmetric/cmdline.c gmetric/cmdline.h	\
				gmond/cmdline.c gmond/cmdline.h		\
				gmond/g25_config.h gmond/gmond.conf.5	\
				gmond/modules/conf.d/modpython.conf	\
				gmond/modules/conf.d/modpython.conf.in	\
				gmond/modules/python/README.in		\
				mans/gmetad.1 mans/gmetric.1 mans/gmond.1
SUBST_SED.pkg_sysconfdir+=	-e 's,/etc/ganglia,${PKG_SYSCONFDIR},g'
SUBST_SED.pkg_sysconfdir+=	-e 's,/usr/lib/ganglia,${PREFIX}/lib/ganglia,g'

DOCDIR=			${PREFIX}/share/doc/ganglia
EGDIR=			${PREFIX}/share/examples/ganglia
CONF_FILES=		${EGDIR}/gmond.conf ${PKG_SYSCONFDIR}/gmond.conf
CONF_FILES+=		${EGDIR}/gmetad.conf ${PKG_SYSCONFDIR}/gmetad.conf

RCD_SCRIPTS=		gmond gmetad

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR} ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

post-install:
	${INSTALL_MAN} ${WRKSRC}/mans/gmetad.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/mans/gmetric.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/mans/gmond.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/mans/gstat.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/gmond/gmond.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/
	${INSTALL_DATA} ${WRKSRC}/gmetad/gmetad.conf ${DESTDIR}${EGDIR}/
	${WRKSRC}/gmond/gmond -t > ${DESTDIR}${EGDIR}/gmond.conf
	${INSTALL_DATA} ${WRKSRC}/gmond/modules/python/README ${DESTDIR}${DOCDIR}/

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../devel/apr/buildlink3.mk"
.include "../../devel/confuse/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
