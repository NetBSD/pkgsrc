# $NetBSD: Makefile,v 1.10 2001/05/13 19:02:47 kim Exp $

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
CONFIGURE_ENV+=	LIBS="${LIBS}"

ALL_TARGET=	vtund
PLIST_SUBST+=	PREFIX=${PREFIX}

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL

.include "../../mk/bsd.prefs.mk"

VTUN_SYSCONFDIR?=${LOCALBASE}/etc
CONFIGURE_ARGS+=--sysconfdir=${VTUN_SYSCONFDIR}
BUILD_DEFS+=	VTUN_SYSCONFDIR

pre-install:
	@${SED}	-e "s|@CAT@|${CAT}|g"					\
		-e "s|@RM@|${RM}|g"					\
		-e "s|@RMDIR@|${RMDIR}|g"				\
		-e "s|@TRUE@|${TRUE}|g"					\
		-e "s|@VTUN_SYSCONFDIR@|${VTUN_SYSCONFDIR}|g"		\
		${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	@${SED}	-e "s|@CAT@|${CAT}|g"					\
		-e "s|@CHMOD@|${CHMOD}|g"				\
		-e "s|@CP@|${CP}|g"					\
		-e "s|@MKDIR@|${MKDIR}|g"				\
		-e "s|@VTUN_SYSCONFDIR@|${VTUN_SYSCONFDIR}|g"		\
		${PKGDIR}/INSTALL > ${INSTALL_FILE}

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
