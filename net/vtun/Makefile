# $NetBSD: Makefile,v 1.13 2001/11/25 19:22:19 jlam Exp $

DISTNAME=	vtun-2.4
CATEGORIES=	net
MASTER_SITES=	http://vtun.sourceforge.net/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://vtun.sourceforge.net/
COMMENT=	Virtual Tunnels over TCP/IP networks with traffic shaping

DEPENDS+=	liblzo-1.*:../../archivers/liblzo

GNU_CONFIGURE=	YES
USE_SSL=	YES
CONFIGURE_ARGS+=--with-ssl-headers=${SSLBASE}/include/openssl \
		--with-ssl-lib=${SSLBASE}/lib \
		--with-lzo-headers=${LOCALBASE}/include \
		--with-lzo-lib=${LOCALBASE}/lib
LIBS+=		${LDFLAGS}

ALL_TARGET=	vtund
PLIST_SUBST+=	PREFIX=${PREFIX}

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

FILES_SUBST=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
FILES_SUBST+=		CAT=${CAT:Q}
FILES_SUBST+=		CHMOD=${CHMOD:Q}
FILES_SUBST+=		CMP=${CMP:Q}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		MKDIR=${MKDIR:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		RMDIR=${RMDIR:Q}
FILES_SUBST+=		TRUE=${TRUE:Q}  
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vtund ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/vtun
	${INSTALL_DATA} ${WRKSRC}/vtund.conf \
		${PREFIX}/share/examples/vtun/vtund.conf.example
	${INSTALL_MAN} ${WRKSRC}/vtund.conf.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/vtund.8 ${PREFIX}/man/man8
	${RM} -f ${PREFIX}/man/man8/vtun.8
	${LN} -s vtund.8 ${PREFIX}/man/man8/vtun.8

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
