# $NetBSD: Makefile,v 1.28 2004/04/01 11:23:32 wiz Exp $

DISTNAME=	oss-${OSS_VERSION}	# Overridden below
PKGNAME=	oss-${OSS_VERSION}
CATEGORIES=	audio sysutils
MASTER_SITES=	ftp://ftp.opensound.com/pub/oss/netbsd/

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.opensound.com/oss.html
COMMENT=	Open Sound System(TM) soundcard driver

#ONLY_FOR_PLATFORM=	NetBSD-1.6-i386 NetBSD-1.6.*-i386
#ONLY_FOR_PLATFORM+=	NetBSD-1.6_*-i386
OSVERSION_SPECIFIC=	yes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DISTNAME=		oss${OSS_VERSION:S/.//g}-netbsd-v1.6.2
OSS_VERSION=		3.9.8e

RESTRICTED=		"No re-distribution."
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

WRKSRC=			${WRKDIR}
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
NO_CONFIGURE=		yes

DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

MODSTAT=		/usr/bin/modstat

CHROOT?=		/usr/sbin/chroot
OSSLIBDIR=		${PREFIX}/lib/oss
FILES_SUBST+=		OSSLIBDIR=${OSSLIBDIR}
FILES_SUBST+=		MODSTAT=${MODSTAT}

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
INSTALLATION_DIRS=	bin sbin

post-extract:
	${MKDIR} ${WRKSRC}
	${MKDIR} ${WRKSRC}/dev
	${MKDIR} ${WRKSRC}/etc
	${CP} ${FILESDIR}/responses ${WRKSRC}
	( ${ECHO} "#!${SH}";						\
	  ${ECHO} "${CAT} responses | ./oss-install"			\
	) > ${WRKSRC}/install.sh
	${CHMOD} +x ${WRKSRC}/install.sh

do-build:
	@for file in ossxmix soundconf; do				\
		${SED}	${FILES_SUBST_SED}				\
			-e "s|@OSS_WRAPPEE@|${OSSLIBDIR}/$${file}|g"	\
			${FILESDIR}/wrapper.sh > ${WRKDIR}/$${file}.sh;	\
	done

# Run the install script in a chroot environment.  The install script tries
# to install into /usr/lib, so we let it install into the chroot'ed /usr/lib
# and then copy the "installed" files to where to really want them.
#
chroot:
	-${PAX} -rw `${CAT} ${FILESDIR}/chroot` ${WRKSRC}
	${CHROOT} -u ${ROOT_USER} -g ${ROOT_GROUP} ${WRKSRC} ./install.sh
	${ECHO} "OSSLIBDIR=${OSSLIBDIR}" > ${WRKSRC}/usr/lib/oss/oss.conf
	${MV} ${WRKSRC}/usr/lib/oss/license.asc				\
		${WRKSRC}/usr/lib/oss/license.asc.eval
	${RM} ${WRKSRC}/usr/lib/oss/*.log

do-install: chroot
	cd ${WRKSRC}/usr && ${PAX} -rw -pe lib/oss ${PREFIX}
	${INSTALL_DATA} ${FILESDIR}/MAKEDEV.oss ${OSSLIBDIR}
	${LN} -sf ../lib/oss/mixer ${PREFIX}/bin/ossmixer
	${LN} -sf ../lib/oss/mplay ${PREFIX}/bin/ossmplay
	${INSTALL_SCRIPT} ${WRKDIR}/ossxmix.sh ${PREFIX}/bin/ossxmix
	${LN} -sf ../lib/oss/play ${PREFIX}/bin/ossplay
	${LN} -sf ../lib/oss/record ${PREFIX}/bin/ossrecord
	${LN} -sf ../lib/oss/savemixer ${PREFIX}/bin/osssavemixer
	${INSTALL_SCRIPT} ${WRKDIR}/soundconf.sh ${PREFIX}/sbin/soundconf
	${LN} -sf ../lib/oss/soundoff ${PREFIX}/sbin/soundoff
	${LN} -sf ../lib/oss/soundon ${PREFIX}/sbin/soundon

	${RM} -rf ${WRKSRC}/bin ${WRKSRC}/sbin ${WRKSRC}/usr
	${RM} -f ${WRKSRC}/dev/mixer0 ${WRKSRC}/dev/null
	${RM} -f ${WRKSRC}/etc/oss.conf
	${RM} -f ${WRKSRC}/etc/*.o3 ${WRKSRC}/etc/*.sb
	${RM} -f ${WRKSRC}/*.core

.include "../../mk/bsd.pkg.mk"
