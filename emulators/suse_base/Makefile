# $NetBSD: Makefile,v 1.1.1.1 1999/05/17 00:14:49 tron Exp $

DISTNAME=	suse_base-6.1
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.suse.com/pub/suse/i386/6.1/suse/a1/
DISTFILES=	aaa_dir.rpm shlibs.rpm ldso.rpm gppshare.rpm
ONLY_FOR_ARCHS=	i386

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.suse.com/

DEPENDS+=	rpm-2.5.4:../../misc/rpm

CONFLICTS=	linux_SuSE-5.3 linux_lib-2.4

DIST_SUBDIR=	suse
MIRROR_DISTFILE= no

EXTRACT_ONLY=	# empty
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_WRKSUBDIR=	yes
MANCOMPRESSED=	yes
INSTALL_FILE=	${WRKDIR}/INSTALL
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

EMULSUBDIR=	emul/linux
EMULDIR=	${PREFIX}/${EMULSUBDIR}
SBINDIR=	${PREFIX}/sbin

do-build:
		@for FILE in ${PKGDIR}/INSTALL ${PKGDIR}/PLIST \
		  ${SCRIPTDIR}/*.sh; do \
		  ${SED} -e 's#@@EMULDIR@@#${EMULDIR}#g' \
		         -e 's#@@EMULSUBDIR@@#${EMULSUBDIR}#g' \
		         -e 's#@@PREFIX@@#${PREFIX}#g' \
		    <$$FILE >${WRKDIR}/`basename $$FILE`; \
		done

do-install:
		cd ${WRKDIR}; \
		for FILE in *.sh; do \
		  ${INSTALL_SCRIPT} $$FILE ${SBINDIR}/`basename $$FILE .sh`; \
		done
		${MKDIR} ${EMULDIR}/dev
		${LN} -fs /dev/sound ${EMULDIR}/dev/dsp
		${LN} -fs /dev/null ${EMULDIR}/dev/null
		@${CP} ${WRKDIR}/PLIST ${PLIST_SRC}
		cd ${_DISTDIR} && \
		${SBINDIR}/rpm2pkg ${DISTFILES} | \
		${EGREP} -v '${EMULSUBDIR}/(tmp|usr/tmp|var)' >>${PLIST_SRC}
		@cd ${EMULDIR} && ${RM} -rf tmp usr/tmp var
		${INSTALL_DATA} ${FILESDIR}/ld.so.conf ${EMULDIR}/etc
		@${ECHO} "@dirrm ${EMULSUBDIR}" >>${PLIST_SRC}
		@${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

show-shlib-type:
		@${ECHO} linux-${MACHINE_ARCH}

.include "../../mk/bsd.pkg.mk"
