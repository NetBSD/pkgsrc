# $NetBSD: Makefile,v 1.2 1998/10/31 00:23:34 tron Exp $

DISTNAME=	SuSE-5.3
PKGNAME=	linux_SuSE-5.3
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.suse.com/pub/SuSE-Linux/5.3/suse/a1/ \
		ftp://ftp.cc.gatech.edu/pub/linux/distributions/suse/5.3/suse/a1/ \
		ftp://ftp.suse.com/pub/SuSE-Linux/5.3/suse/x1/ \
		ftp://ftp.cc.gatech.edu/pub/linux/distributions/suse/5.3/suse/a1/
DISTFILES=	${BASE_RPM} ${EXTRA_RPM}
ONLY_FOR_ARCHS=	i386

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.suse.com/

DEPENDS+=	rpm-2.5.1:../../misc/rpm

CONFLICTS=	linux_lib-2.4

DIST_SUBDIR=	SuSE
MIRROR_DISTFILE= no

EXTRACT_ONLY=	# empty
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_WRKSUBDIR=	yes
MANCOMPRESSED=	yes
INSTALL_FILE=	${WRKDIR}/INSTALL
PLIST_SRC=	${WRKDIR}/PLIST

BASE_RPM=	aaa_dir.rpm shlibs.rpm ldso.rpm
EXTRA_RPM=	gppshare.rpm shlibs6.rpm xshared.rpm xpm.rpm

BINDIR=		${PREFIX}/sbin
EMULDIR=	${PREFIX}/emul/linux
LDSOCONFDIRS=	/usr/X11R6/lib /usr/i486-linux-libc6/lib

do-build:
		@for FILE in ${PKGDIR}/INSTALL ${SCRIPTDIR}/*.sh; do \
		  ${SED} -e 's#@@EMULDIR@@#${EMULDIR}#g' \
		    <$$FILE >${WRKSRC}/`basename $$FILE`; \
		done
		@${TOUCH} ${WRKSRC}/ld.so.conf
.for DIR in ${LDSOCONFDIRS}
		@echo ${DIR} >>${WRKSRC}/ld.so.conf
.endfor

do-install:
		@cd ${WRKSRC}; \
		for FILE in *.sh; do \
		  ${INSTALL_SCRIPT} $$FILE ${BINDIR}/`basename $$FILE .sh`; \
		done
		@${MKDIR} ${EMULDIR}/dev ${EMULDIR}/var/pkg/lib/rpm
		${BINDIR}/linux-rpm -i ${DISTDIR}/${DIST_SUBDIR}/aaa_dir.rpm \
		  2>/dev/null
		@${RM} -rf ${EMULDIR}/tmp ${EMULDIR}/usr/tmp \
		  ${EMULDIR}/var/log ${EMULDIR}/var/run ${EMULDIR}/var/tmp
		@find ${EMULDIR} -type d | tee ${WRKDIR}/DIRS | \
		${AWK} '{print($$1"/.keep_me")}' | xargs ${TOUCH}
		@find ${EMULDIR} -type f -name .keep_me | sort | \
		${SED} -e 's#${PREFIX}/##' >${PLIST_SRC}
		@${CAT} ${PKGDIR}/PLIST >>${PLIST_SRC}
		@find ${EMULDIR} -type l | xargs ${RM}
		@sort -r <${WRKDIR}/DIRS | \
		${SED} -e 's#${PREFIX}/#@dirrm #' >>${PLIST_SRC}
		@${LN} -fs /dev/sound ${EMULDIR}/dev/dsp
		@mknod ${EMULDIR}/dev/null c 2 2
		@${CHMOD} 666 ${EMULDIR}/dev/null
		@${BINDIR}/linux-mkpwd
		@${INSTALL_DATA} ${WRKSRC}/ld.so.conf ${EMULDIR}/etc
		${BINDIR}/linux-rpm -i ${DISTDIR}/${DIST_SUBDIR}/shlibs.rpm
		${BINDIR}/linux-rpm -i --nodeps --noscripts \
		  ${DISTDIR}/${DIST_SUBDIR}/ldso.rpm
.for RPM in ${EXTRA_RPM}
		${BINDIR}/linux-rpm -i ${DISTDIR}/${DIST_SUBDIR}/${RPM}
.endfor
		@${EMULDIR}/sbin/ldconfig -r ${EMULDIR} || ${TRUE}

post-install:
		@${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
