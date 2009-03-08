# $NetBSD: Makefile,v 1.23 2009/03/08 06:15:31 hasso Exp $
#

DISTNAME=		ganglia-3.0.1
PKGNAME=		ganglia-monitor-core-3.0.1
PKGREVISION=		9
CATEGORIES=		net parallel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ganglia/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ganglia.sourceforge.net/
COMMENT=		Ganglia cluster monitor, monitoring daemon

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-gmetad
USE_LIBTOOL=		yes
CONFIG_GUESS_OVERRIDE?=		\
	config.guess */config.guess */*/config.guess */*/*/config.guess
CONFIG_SUB_OVERRIDE?=		\
	config.sub */config.sub */*/config.sub */*/*/config.sub

PATCH_ETC=		mans/gmetad.1 mans/gmond.1			\
			gmetad/cmdline.c gmetad/conf.c 			\
			gmond/cmdline.c gmond/g25_config.h		\
			ganglia.html

EGDIR=			${PREFIX}/share/examples/ganglia
CONF_FILES=		${EGDIR}/gmond.conf ${PKG_SYSCONFDIR}/gmond.conf
CONF_FILES+=		${EGDIR}/gmetad.conf ${PKG_SYSCONFDIR}/gmetad.conf

RCD_SCRIPTS=		gmond gmetad

INSTALLATION_DIRS=	${EGDIR} ${PKGMANDIR}/man1

pre-patch:
	${MKDIR} ${WRKSRC}/srclib/libmetrics/netbsd
	${MKDIR} ${WRKSRC}/srclib/libmetrics/dragonfly
	${CP} ${FILESDIR}/dfly-metrics.c ${WRKSRC}/srclib/libmetrics/dragonfly/metrics.c
	${CP} ${FILESDIR}/dfly-Makefile.am ${WRKSRC}/srclib/libmetrics/dragonfly/Makefile.am
	${CP} ${FILESDIR}/dfly-Makefile.in ${WRKSRC}/srclib/libmetrics/dragonfly/Makefile.in

post-patch:
.for pfile in ${PATCH_ETC}
	${SED} -e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g' 		\
		${WRKSRC}/${pfile} > ${WRKSRC}/${pfile}.tmp &&		\
		${MV}  ${WRKSRC}/${pfile}.tmp ${WRKSRC}/${pfile}
.endfor

post-install:
	${INSTALL_MAN} ${WRKSRC}/mans/gmetad.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/mans/gmetric.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/mans/gmond.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/mans/gstat.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/gmetad/gmetad.conf ${DESTDIR}${EGDIR}/
	${DESTDIR}${PREFIX}/sbin/gmond -t > ${DESTDIR}${EGDIR}/gmond.conf

BUILDLINK_DEPENDS.apr+=	apr>=0.9.7.2.0.55nb3

.include "../../devel/apr0/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../databases/rrdtool/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
