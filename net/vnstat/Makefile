# $NetBSD: Makefile,v 1.31 2026/04/08 13:35:58 sborrill Exp $

CONF_FILES=	${VNSTAT_EGDIR}/vnstat.conf ${VNSTAT_CONFIG}

CONFIGURE_ARGS+=	--disable-image-output
RCD_SCRIPTS=		vnstatd

VNSTAT_CONFIG=	${PKG_SYSCONFDIR}/vnstat.conf
VNSTAT_EGDIR=	${PREFIX}/share/examples

INSTALLATION_DIRS=	bin ${VNSTAT_EGDIR} ${PKGMANDIR}/man1 \
			${PKGMANDIR}/man5 ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vnstat				\
		${DESTDIR}${PREFIX}/bin/vnstat
	${INSTALL_PROGRAM} ${WRKSRC}/vnstatd				\
		${DESTDIR}${PREFIX}/bin/vnstatd
	${INSTALL_DATA} ${WRKSRC}/cfg/vnstat.conf 			\
		${DESTDIR}${VNSTAT_EGDIR}/vnstat.conf
	${INSTALL_MAN} ${WRKSRC}/man/vnstat.1 				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vnstat.1
	${INSTALL_MAN} ${WRKSRC}/man/vnstatd.8 				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/vnstatd.8
	${INSTALL_MAN} ${WRKSRC}/man/vnstat.conf.5 			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/vnstat.conf.5

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
