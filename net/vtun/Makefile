# $NetBSD: Makefile,v 1.14 2001/12/21 21:04:23 jlam Exp $

DISTNAME=	vtun-2.4
CATEGORIES=	net
MASTER_SITES=	http://vtun.sourceforge.net/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://vtun.sourceforge.net/
COMMENT=	Virtual Tunnels over TCP/IP networks with traffic shaping

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=/var
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-ssl-headers=${BUILDLINK_DIR}/include/openssl
CONFIGURE_ARGS+=	--with-ssl-lib=${BUILDLINK_DIR}/lib
CONFIGURE_ARGS+=	--with-lzo-headers=${BUILDLINK_DIR}/include
CONFIGURE_ARGS+=	--with-lzo-lib=${BUILDLINK_DIR}/lib
ALL_TARGET=		vtund

DOCDIR=			${PREFIX}/share/doc/vtun
EGDIR=			${PREFIX}/share/examples/vtun
LOCKDIR=		/var/run/vtund
LOGDIR=			/var/log/vtund

CONF_FILES_PERMS=	${EGDIR}/vtund.conf ${PKG_SYSCONFDIR}/vtund.conf \
			${ROOT_USER} ${ROOT_GROUP} 0600
OWN_DIRS=		${LOCKDIR} ${LOGDIR}

post-build:
	@cd ${WRKSRC}; for file in vtund.8; do				\
		${SED}	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"	\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done
	${SED}	-e "/^[^#]/s|^|#|" -e "s|^$$|#|" ${WRKSRC}/vtund.conf	\
		> ${WRKDIR}/vtund.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vtund ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${DOCDIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README.Setup ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.Shaper ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/vtund.conf ${EGDIR}/vtund.conf
	${INSTALL_MAN} ${WRKSRC}/vtund.conf.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/vtund.8 ${PREFIX}/man/man8
	${RM} -f ${PREFIX}/man/man8/vtun.8
	${LN} -s vtund.8 ${PREFIX}/man/man8/vtun.8

.include "../../archivers/liblzo/buildlink.mk"
.include "../../devel/zlib/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
