# $NetBSD: Makefile,v 1.6 2000/04/28 10:23:43 sakamoto Exp $
#

DISTNAME=	locales-2.1-1mdk
PKGNAME=	linux-locale-2.1.1
CATEGORIES=	emulators
MASTER_SITES=	http://www.linuxi18n.org/locales/
EXTRACT_SUFX=	.noarch.rpm
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.linuxi18n.org/locales/

BUILD_DEPENDS+=	rpm2cpio:../../misc/rpm

.include "../../mk/bsd.prefs.mk"
.if !defined(LINUX_LOCALES)
LINUX_LOCALES= \
	af ar bg br ca cs cy da de el en eo es et eu fi fo fr ga gl \
	he hr hu hy id is it ja ka kl ko lo lt lv nl no oc pl pt ro \
	ru sk sl sr sv th tr uk vi wa zh
#	fa gd gv iu kw ml ms pd
.endif

.for locale in ${LINUX_LOCALES}
DISTFILES+=	locales-${locale}-2.1-1mdk${EXTRACT_SUFX}
.endfor

DIST_SUBDIR=	linux-locale

ONLY_FOR_PLATFORM=NetBSD-*-i386
DEPENDS=	suse_linux-6.3:../../emulators/suse_linux

EXTRACT_ONLY=	# empty
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

EMULSUBDIR=	emul/linux
EMULDIR=	${PREFIX}/${EMULSUBDIR}
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC
CPIOLIST=	${WRKDIR}/CPIOLIST

do-install:
	@${MV} ${EMULDIR}/usr/share/locale ${EMULDIR}/usr/share/locale.orig
	@${RM} -f ${CPIOLIST}
.for f in ${DISTFILES}
	@rpm2cpio ${DISTDIR}/${DIST_SUBDIR}/${f}|cpio -t -v >> ${CPIOLIST}
	@(cd ${EMULDIR}; rpm2cpio ${DISTDIR}/${DIST_SUBDIR}/${f}|cpio -i -d)
.endfor
	@${CHMOD} 755 ${EMULDIR}/usr/share/locale

post-install:
	@${ECHO} "@exec ${MV} ${EMULDIR}/usr/share/locale ${EMULDIR}/usr/share/locale.orig" > ${PLIST_SRC}
	@${CAT} ${CPIOLIST}|${GREP} "^d"|${SED} -e "s|.* \(usr\/.*\)|@exec ${MKDIR} ${EMULDIR}/\1|"|sort >> ${PLIST_SRC}
	@${CAT} ${CPIOLIST}|${GREP} "^-"|${SED} -e "s|.* \(usr\/.*\)|${EMULSUBDIR}/\1|"|sort >> ${PLIST_SRC}
	@${CAT} ${CPIOLIST}|${GREP} "^l"|${SED} -e "s|.* \(usr\/.*\) -> \(.*\)|@exec ln -s \2 %D/${EMULSUBDIR}/\1|"|sort >> ${PLIST_SRC}
	@${CAT} ${CPIOLIST}|${GREP} "^l"|${SED} -e "s|.* \(usr\/.*\) -> .*|@unexec rm -f %D/${EMULSUBDIR}/\1|"|sort >> ${PLIST_SRC}
	@${CAT} ${CPIOLIST}|${GREP} "^d"|${SED} -e "s|.* \(usr\/.*\)|@dirrm ${EMULSUBDIR}/\1|"|sort -r >> ${PLIST_SRC}
	@${ECHO} "@dirrm ${EMULSUBDIR}/usr/share/locale" >> ${PLIST_SRC}
	@${ECHO} "@unexec ${MV} ${EMULDIR}/usr/share/locale.orig ${EMULDIR}/usr/share/locale" >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
