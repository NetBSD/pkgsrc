# $NetBSD: Makefile,v 1.1.1.1 2000/12/27 15:44:55 hubertf Exp $
# FreeBSD Id: ports/sysutils/daemontools/Makefile,v 1.8 2000/12/03 05:16:41 steve Exp

DISTNAME=	daemontools-0.70
CATEGORIES=	sysutils
MASTER_SITES=	http://cr.yp.to/daemontools/ \
		ftp://cr.yp.to/daemontools/ \
		http://zuntum.eik.pl/pkgsrc/distfiles/

PATCH_SITES=  	http://www.fefe.de/daemontools/
PATCHFILES=	daemontools-0.70-man.diff.bz2
PATCH_DIST_STRIP=       -p1

MAINTAINER=	zuntum@eik.pl
HOMEPAGE=	http://cr.yp.to/daemontools.html

ALL_TARGET=	it
INSTALL_TARGET=	setup check
SAMPLERC=	svscan.sh.sample
SERVICEDIR?=	/var/spool/service

PLIST_SUBST+=	SERVICEDIR=${SERVICEDIR}
DEINSTALL_FILE=	${WRKDIR}/.DEINSTALL

post-patch:
	@${ECHO} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO} "${CC} -s" > ${WRKSRC}/conf-ld
	@${ECHO} "${PREFIX}" > ${WRKSRC}/conf-home

post-build:
	@${SED} \
		-e "s!/usr/local/!${PREFIX}/!" \
		-e "s!/var/service!${SERVICEDIR}!g" \
		${FILESDIR}/${SAMPLERC} > ${WRKDIR}/${SAMPLERC}
	@${SED} \
		-e "s!/var/service!${SERVICEDIR}!g" \
		${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/daemontools
	${INSTALL_DATA} ${WRKDIR}/${SAMPLERC} ${PREFIX}/share/examples/daemontools
	${INSTALL_DATA_DIR} ${SERVICEDIR}

.include "../../mk/bsd.pkg.mk"
