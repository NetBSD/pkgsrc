# $NetBSD: Makefile,v 1.1.1.1 2005/02/07 14:33:19 jschauma Exp $
#

DISTNAME=		ganglia-monitor-core-2.5.7
CATEGORIES=		net parallel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ganglia/}

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://ganglia.sourceforge.net/
COMMENT=		Ganglia cluster monitor, monitoring daemon

HAS_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-gmetad

PATCH_ETC=		lib/ganglia/gmond_config.h			\
			mans/gmetad.1 mans/gmond.1			\
			gmetad/cmdline.c gmond/cmdline.c

PATCH_RCS=		gmond gmetad

EGDIR=			${PREFIX}/share/examples/ganglia
CONF_FILES=		${EGDIR}/gmond.conf ${PKG_SYSCONFDIR}/gmond.conf
CONF_FILES+=		${EGDIR}/gmetad.conf ${PKG_SYSCONFDIR}/gmetad.conf

RCD_SCRIPTS=		gmond gmetad

post-patch:
.for pfile in ${PATCH_ETC}
	${SED} -e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g' 		\
		${WRKSRC}/${pfile} > ${WRKSRC}/${pfile}.tmp &&		\
		${MV}  ${WRKSRC}/${pfile}.tmp ${WRKSRC}/${pfile}
.endfor
.for pfile in ${PATCH_RCS}
	${SED} -e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g'		\
		-e 's|@PREFIX@|${PREFIX}|g'				\
		-e 's|@RCD_SCRIPTS_SHELL@|${RCD_SCRIPTS_SHELL}|g'	\
		${FILESDIR}/${pfile}.in > ${WRKSRC}/${pfile}.sh
.endfor

post-install:
	${INSTALL_MAN} ${WRKSRC}/mans/gmetad.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/mans/gmetric.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/mans/gmond.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/mans/gstat.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ganglia
	${INSTALL_DATA_DIR} ${PREFIX}/${RCD_SCRIPTS_EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/gmond/gmond.conf ${PREFIX}/share/examples/ganglia/
	${INSTALL_DATA} ${WRKSRC}/gmetad/gmetad.conf ${PREFIX}/share/examples/ganglia/
	${INSTALL_DATA} ${WRKSRC}/gmond.sh ${PREFIX}/${RCD_SCRIPTS_EXAMPLEDIR}/gmond
	${INSTALL_DATA} ${WRKSRC}/gmetad.sh ${PREFIX}/${RCD_SCRIPTS_EXAMPLEDIR}/gmetad

CFLAGS+=-g
LDFLAGS+=-g

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
