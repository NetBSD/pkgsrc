# $NetBSD: Makefile,v 1.1.1.1 2000/01/27 21:18:55 abs Exp $
#

DISTNAME=	fmlinux
PKGNAME=	framemaker-5.5.6
CATEGORIES=	editors textproc
MASTER_SITES=	ftp://ftp.adobe.com/pub/adobe/magic/framemaker/unix/5.x/ \
		ftp://ftp.adobe.com/pub/adobe/magic/framemaker/unix/5.x/beta/
DISTFILES=	fmlinux.txt fmlinux.tar.gz dictionaries.txt \
		dictionaries.tar.gz help.txt help.tar.gz manuals.txt \
		manuals.tar.gz

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.adobe.com/products/framemaker/fmlinux.html

.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "i386")
DEPENDS=        suse_linux>=6.1:../../emulators/suse_linux
.endif

MIRROR_DISTFILE=NO

NO_CONFIGURE=	YES
NO_PACKAGE=
NO_CDROM=

DIST_SUBDIR=	framemaker

# BROKEN=	Does not work with suse 6.3 shlibs.rpm - needs 6.1
ONLY_FOR_PLATFORM=*-*-i386

WRKSRC=		${WRKDIR}/FM556_linux
PLIST_SRC=	${WRKDIR}/PLIST.src
FMHOME=		${PREFIX}/lib/FM556_linux
FMARCH=		bin/scripts/fmarch
WRAPPERS=	fmaddlicense maker demomaker

EXTRACT_ONLY=	fmlinux.tar.gz
EXTRACT_CMD=	${GTAR} xvzf ${_DISTDIR}/fmlinux.tar.gz FM556_linux/${FMARCH}

do-build:
.for wrap in ${WRAPPERS}
	@${SED} -e 's|@@PREFIX@@|${PREFIX}|g' -e 's|@@COMMAND@@|${wrap}|g' \
		${FILESDIR}/wrapper > ${WRKDIR}/${wrap}
.endfor

do-install:
	@${GTAR} xzvCf ${PREFIX}/lib ${_DISTDIR}/fmlinux.tar.gz
	@${GTAR} xzvCf ${FMHOME}/fminit/usenglish ${_DISTDIR}/manuals.tar.gz
	@${GTAR} xzvCf ${FMHOME}/fminit/usenglish ${_DISTDIR}/help.tar.gz
	@${GTAR} xzvCf ${FMHOME}/fminit ${_DISTDIR}/dictionaries.tar.gz
	@${INSTALL_SCRIPT} ${WRKSRC}/${FMARCH} ${FMHOME}/${FMARCH}
.for wrap in ${WRAPPERS}
	@${INSTALL_SCRIPT} ${WRKDIR}/${wrap} ${PREFIX}/bin
.endfor
	@${LN} -s maker ${PREFIX}/bin/framemaker

post-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(cd ${PREFIX}; \
	 ${FIND} lib/FM556_linux \( -type f -or -type l \) | \
	   sort >> ${PLIST_SRC}; \
	 for DIR in `${FIND} lib/FM556_linux -type d | sort -r`; do \
	   ${ECHO} "@dirrm $$DIR" >> ${PLIST_SRC}; \
	 done)

.include "../../mk/bsd.pkg.mk"
