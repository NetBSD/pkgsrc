# $NetBSD: Makefile,v 1.10 2002/04/18 16:23:22 yyamano Exp $
# FreeBSD Id: ports/sysutils/daemontools/Makefile,v 1.8 2000/12/03 05:16:41 steve Exp

DISTNAME=	daemontools-0.70
CATEGORIES=	sysutils
MASTER_SITES=	http://cr.yp.to/daemontools/				\
		ftp://cr.yp.to/daemontools/				\
		ftp://ftp.innominate.org/pub/pape/djb/
DISTFILES=	${DISTNAME}.tar.gz					\
		${DISTNAME}-man-20001116.tar.gz

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://cr.yp.to/daemontools.html
COMMENT=	Service monitoring and logging utilities by djb

RESTRICTED=	"Redistribution of modified package is forbidden"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

ALL_TARGET=	it
INSTALL_TARGET=	setup check
SAMPLERC=	svscan.sh.sample
SERVICEDIR?=	/var/spool/service

PLIST_SUBST+=	SERVICEDIR=${SERVICEDIR}
DEINSTALL_FILE=	${WRKDIR}/.DEINSTALL

post-patch:
	@${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	@${ECHO} ${PREFIX} > ${WRKSRC}/conf-home

post-build:
	${SED}	-e "s,@@PREFIX@@,${PREFIX},"				\
		-e "s,@@SERVICEDIR@@,${SERVICEDIR},g"			\
		${FILESDIR}/${SAMPLERC} > ${WRKDIR}/${SAMPLERC}
	${SED}	"s,@@SERVICEDIR@@,${SERVICEDIR},g"			\
		${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/daemontools
	${INSTALL_DATA} ${WRKDIR}/${SAMPLERC}				\
		${PREFIX}/share/examples/daemontools
	${INSTALL_DATA_DIR} ${SERVICEDIR}

	cd ${WRKDIR}/${DISTNAME}-man && 				\
		${INSTALL_MAN} *.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
