# $NetBSD: Makefile,v 1.15 2002/04/05 09:36:44 tron Exp $

DISTNAME=	locales-2.1-1mdk
PKGNAME=	linux-locale-2.1.1
CATEGORIES=	emulators
MASTER_SITES=	http://www.linuxi18n.org/locales/
EXTRACT_SUFX=	.noarch.rpm
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.linuxi18n.org/locales/
COMMENT=	Locales for Linux

BUILD_DEPENDS+=	rpm-[0-9]*:../../misc/rpm

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
DEPENDS=	suse_base>=6.3:../../emulators/${SUSE_DIR_PREFIX}_base

EXTRACT_ONLY=	# empty
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

EMULSUBDIR=	emul/linux
EMULDIR=	${PREFIX}/${EMULSUBDIR}
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC
EXCLUDELIST=	${WRKDIR}/EXCLUDE
CPIOLIST=	${WRKDIR}/CPIOLIST
CHECK_SHLIBS=	no

do-install:
	@${RM} -f ${CPIOLIST}
	@(cd ${EMULDIR}; \
		${FIND} usr/share/locale -name "*" > ${EXCLUDELIST})
.for f in ${DISTFILES}
	@rpm2cpio ${DISTDIR}/${DIST_SUBDIR}/${f} | \
		cpio -t -v -f -E ${EXCLUDELIST} >> ${CPIOLIST}
	@(cd ${EMULDIR}; rpm2cpio ${DISTDIR}/${DIST_SUBDIR}/${f} | \
		cpio -i -d -f -E ${EXCLUDELIST})
.endfor

post-install:
	@${CAT} ${CPIOLIST}|${GREP} "^d"|${SED} -e "s|.* \(usr\/.*\)|@exec ${MKDIR} ${EMULDIR}/\1|"|sort >> ${PLIST_SRC}
	@${CAT} ${CPIOLIST}|${GREP} "^-"|${SED} -e "s|.* \(usr\/.*\)|${EMULSUBDIR}/\1|"|sort >> ${PLIST_SRC}
	@${CAT} ${CPIOLIST}|${GREP} "^l"|${SED} -e "s|.* \(usr\/.*\) -> \(.*\)|@exec ln -s \2 %D/${EMULSUBDIR}/\1|"|sort >> ${PLIST_SRC}
	@${CAT} ${CPIOLIST}|${GREP} "^l"|${SED} -e "s|.* \(usr\/.*\) -> .*|@unexec rm -f %D/${EMULSUBDIR}/\1|"|sort >> ${PLIST_SRC}
	@${CAT} ${CPIOLIST}|${GREP} "^d"|${SED} -e "s|.* \(usr\/.*\)|@dirrm ${EMULSUBDIR}/\1|"|sort -r >> ${PLIST_SRC}

.include "../../emulators/suse_linux/Makefile.application"
