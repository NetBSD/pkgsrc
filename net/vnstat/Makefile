# $NetBSD: Makefile,v 1.8 2013/01/26 21:38:38 adam Exp $

DISTNAME=	vnstat-1.11
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://humdi.net/vnstat/
#DISTFILES=${DISTNAME}.tar.gz

MAINTAINER=	sborrill@NetBSD.org
HOMEPAGE=	http://humdi.net/vnstat/
COMMENT=	Small network traffic monitor
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

VNSTAT_CONFIG=	${PKG_SYSCONFDIR}/vnstat.conf
VNSTAT_EGDIR=	${PREFIX}/share/examples

SUBST_CLASSES+=			fix-dbpath
SUBST_STAGE.fix-dbpath=		pre-configure
SUBST_MESSAGE.fix-dbpath=	Fixing path to database files
SUBST_FILES.fix-dbpath=		src/common.h cfg/vnstat.conf
SUBST_FILES.fix-dbpath+=	man/vnstat.1 man/vnstatd.1
SUBST_FILES.fix-dbpath+=	man/vnstati.1
SUBST_SED.fix-dbpath=		-e 's,/var/lib/,${VARBASE}/db/,g'

SUBST_CLASSES+=			fix-etcpath
SUBST_STAGE.fix-etcpath=	pre-configure
SUBST_MESSAGE.fix-etcpath=	Fixing path to configuration files
SUBST_FILES.fix-etcpath=	src/cfg.c
SUBST_FILES.fix-etcpath+=	man/vnstat.1 man/vnstatd.1
SUBST_FILES.fix-etcpath+=	man/vnstati.1
SUBST_SED.fix-etcpath=		-e 's,/etc/,${PKG_SYSCONFDIR}/,g'

CONF_FILES= ${VNSTAT_EGDIR}/vnstat.conf ${VNSTAT_CONFIG}

RCD_SCRIPTS=	vnstatd

BUILD_DEFS+=	VARBASE

INSTALLATION_DIRS=	bin ${VNSTAT_EGDIR} ${PKGMANDIR}/man1 \
			${PKGMANDIR}/man5

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/vnstat				\
		${DESTDIR}${PREFIX}/bin/vnstat
	${INSTALL_PROGRAM} ${WRKSRC}/src/vnstatd			\
		${DESTDIR}${PREFIX}/bin/vnstatd
	${INSTALL_DATA} ${WRKSRC}/cfg/vnstat.conf 			\
		${DESTDIR}${VNSTAT_EGDIR}/vnstat.conf
	${INSTALL_MAN} ${WRKSRC}/man/vnstat.1 				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vnstat.1
	${INSTALL_MAN} ${WRKSRC}/man/vnstatd.1 				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vnstatd.1
	${INSTALL_MAN} ${WRKSRC}/man/vnstat.conf.5 			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/vnstat.conf.5
	if [ ${PLIST.gd:Q} = "yes" ]; then				\
		${INSTALL_PROGRAM} ${WRKSRC}/src/vnstati		\
		    ${DESTDIR}${PREFIX}/bin/vnstati;			\
		${INSTALL_MAN} ${WRKSRC}/man/vnstati.1 			\
		    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vnstati.1;	\
	fi

.include "../../mk/bsd.pkg.mk"
