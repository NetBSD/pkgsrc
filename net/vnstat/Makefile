# $NetBSD: Makefile,v 1.32 2026/04/08 16:08:47 sborrill Exp $

# Version is in Makefile.common shared with net/vnstati
# PKGREVISION can be bumped here

PKGREVISION=	1

CONF_FILES=	${VNSTAT_EGDIR}/vnstat.conf ${VNSTAT_CONFIG}

CONFIGURE_ARGS+=	--disable-image-output

RCD_SCRIPTS=		vnstatd

VNSTAT_CONFIG=	${PKG_SYSCONFDIR}/vnstat.conf
VNSTAT_EGDIR=	${PREFIX}/share/examples/${PKGBASE}

INSTALLATION_DIRS=	bin ${EGDIR} ${VNSTAT_EGDIR} ${PKGMANDIR}/man1 \
			${PKGMANDIR}/man5 ${PKGMANDIR}/man8

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/vnstat.conf \
	    ${DESTDIR}${VNSTAT_EGDIR}/vnstat.conf
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vnstati.1

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
