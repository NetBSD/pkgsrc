# $NetBSD: Makefile,v 1.1.1.1 2002/10/02 20:33:30 jlam Exp $

DISTNAME=	oss397d-netbsd-v1.6
PKGNAME=	oss-3.97d
CATEGORIES=	audio sysutils
MASTER_SITES=	ftp://ftp.opensound.com/pub/oss/netbsd/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.opensound.com/oss.html
COMMENT=	Open Sound System(TM) soundcard driver

ONLY_FOR_PLATFORM=	NetBSD-1.6-i386 NetBSD-1.6.*-i386

RESTRICTED=		"No re-distribution."
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

USE_BUILDLINK2=		# defined
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

CHROOT?=		/usr/sbin/chroot
WRKSRC=			${WRKDIR}
OSSLIBDIR=		${PREFIX}/lib/oss
FILES_SUBST+=		OSSLIBDIR=${OSSLIBDIR}

# OSS needs to find certain files in /etc, so this package can't be
# made to honor ${PKG_SYSCONFDIR}.
#
SFILES=			drums.o3 drums.sb oss.conf std.o3 std.sb
FILES_SUBST+=		SFILES=${SFILES:Q}
.for FILE in ${SFILES}
SUPPORT_FILES+=		${OSSLIBDIR}/${FILE} /etc/${FILE}
.endfor
SUPPORT_FILES+=		${OSSLIBDIR}/license.asc.eval ${OSSLIBDIR}/license.asc
RCD_SCRIPTS=		oss

post-extract:
	${MKDIR} ${WRKSRC}
	${MKDIR} ${WRKSRC}/dev
	${MKDIR} ${WRKSRC}/etc
	${CP} ${FILESDIR}/responses ${WRKSRC}
	( ${ECHO} "#!${SH}";						\
	  ${ECHO} "${CAT} responses | ./oss-install"			\
	) > ${WRKSRC}/install.sh
	${CHMOD} +x ${WRKSRC}/install.sh

chroot:
	${PAX} -rw `${CAT} ${FILESDIR}/chroot` ${WRKSRC}
	${CHROOT} -u ${ROOT_USER} -g ${ROOT_GROUP} ${WRKSRC} ./install.sh
	${ECHO} "OSSLIBDIR=${OSSLIBDIR}" > ${WRKSRC}/usr/lib/oss/oss.conf
	${MV} ${WRKSRC}/usr/lib/oss/license.asc				\
		${WRKSRC}/usr/lib/oss/license.asc.eval
	${RM} ${WRKSRC}/usr/lib/oss/*.log

do-install: chroot
	cd ${WRKSRC}/usr; ${PAX} -rwpe lib/oss ${PREFIX}
	${INSTALL_DATA} ${FILESDIR}/MAKEDEV.oss ${OSSLIBDIR}
	${LN} -sf ../lib/oss/mixer ${PREFIX}/bin/ossmixer
	${LN} -sf ../lib/oss/mplay ${PREFIX}/bin/ossmplay
	${LN} -sf ../lib/oss/ossxmix ${PREFIX}/bin/ossxmix
	${LN} -sf ../lib/oss/play ${PREFIX}/bin/ossplay
	${LN} -sf ../lib/oss/record ${PREFIX}/bin/ossrecord
	${LN} -sf ../lib/oss/savemixer ${PREFIX}/bin/osssavemixer
	${LN} -sf ../lib/oss/soundconf ${PREFIX}/bin/soundconf
	${LN} -sf ../lib/oss/soundoff ${PREFIX}/bin/soundoff
	${LN} -sf ../lib/oss/soundon ${PREFIX}/bin/soundon

	${RM} -rf ${WRKSRC}/bin ${WRKSRC}/sbin ${WRKSRC}/usr
	${RM} -f ${WRKSRC}/dev/mixer0 ${WRKSRC}/dev/null
	${RM} -f ${WRKSRC}/etc/oss.conf
	${RM} -f ${WRKSRC}/etc/*.o3 ${WRKSRC}/etc/*.sb
	${RM} -f ${WRKSRC}/*.core

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
