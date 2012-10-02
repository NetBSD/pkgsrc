# $NetBSD: Makefile,v 1.96 2012/10/02 20:11:40 asau Exp $

DISTNAME=		gcc-2.95.3
PKGREVISION=		7
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/}

PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCHFILES=		gcc-2.95.3-diff-2002-08-29.gz

#
# Synced from patches against main source tree as of 2002-03-28
#
MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gcc.gnu.org/
COMMENT=		GNU Compiler Collection, version 2

NOT_FOR_PLATFORM=	Darwin-*-* Interix-*-* *-*-x86_64 DragonFly-*-*

USE_TOOLS+=		gmake bison
MAKEFLAGS+=		GMAKE_LOCALE=no

HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	${WRKSRC}/configure
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM:Q}
CONFIGURE_ARGS+=	--prefix=${GCC_PREFIX:Q}
CONFIGURE_ARGS+=	--enable-shared

USE_TOOLS+=		chmod
MAKE_ENV+=		ac_cv_prog_chmod=${TOOLS_CHMOD:Q}
MAKE_ENV+=		SHELL=${CONFIG_SHELL}

CONFIGURE_DIRS=		${WRKDIR}/objdir
BUILD_DIRS=		${CONFIGURE_DIRS}

FILES_SUBST+=		DISTNAME=${DISTNAME:Q}				\
			GCC_PREFIX=${GCC_PREFIX:Q}
MESSAGE_SUBST+=		DISTNAME=${DISTNAME}
PLIST_SUBST+=		DISTNAME=${DISTNAME:Q}				\
			GCC_PREFIX=${GCC_PREFIX:S|^${PREFIX}/||:Q}

INFO_FILES=		# PLIST

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-4*)
GCC_REQD+=		3.0
USE_PKGSRC_GCC=		yes
.endif

.if ${OPSYS} == "SunOS"
CONFLICTS+=		gcc-[0-9]* pgcc-[0-9]*
.  if ${CC:M*gcc*} == ""
BUILD_TARGET=		bootstrap
.  endif
# we know it's a GNU toolchain on Linux and the BSDs.
.elif ${OPSYS:M*BSD} != "" || ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-gnu-as
CONFIGURE_ARGS+=	--with-gnu-ld
.else
# play it safe, force a bootstrap build if we don't know for sure it
# is gcc.
.  if ${CC:M*gcc*} == ""
BUILD_TARGET=		bootstrap
.  endif
.endif

GCC_PREFIX=	${PREFIX}/${DISTNAME}
GCC_VERSION=	${PKGVERSION:C|nb.*||}
GCC_ARCHDIR=	${GCC_PREFIX}/lib/gcc-lib/${MACHINE_GNU_PLATFORM}/${GCC_VERSION}

post-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/xm-netbsd.h ${WRKSRC}/gcc/config
	${CP} ${FILESDIR}/xm-target64.h ${WRKSRC}/gcc/config
	for file in ${FILESDIR}/*_* ; do \
		arch=`${BASENAME} $${file} | ${SED} -e "s/_.*//"`;	\
		dest=`${BASENAME} $${file} | ${SED} -e "s/$${arch}_//"`; \
		${MKDIR} ${WRKSRC}/gcc/config/$${arch};			\
		${CP} $${file} ${WRKSRC}/gcc/config/$${arch}/$${dest};	\
	done
	${RM} ${WRKSRC}/gcc/config/alpha/netbsd-elf.h
	${RM} ${WRKSRC}/gcc/config/arm/t-netbsd
	${RM} ${WRKSRC}/gcc/config/mips/x-netbsd
	${RM} ${WRKSRC}/libf2c/libF77/dtime_.c
	${RM} ${WRKSRC}/libf2c/libF77/etime_.c

pre-configure:
	${MKDIR} ${BUILD_DIRS}
	cd ${WRKSRC} && contrib/egcs_update --touch

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/gcc.mk > ${WRKDIR}/gcc.mk

.if ${OPSYS} == "SunOS"
#
# remove empty file and directories that show up when one does:
#	make install; make deinstall; make install
#
post-install:
	-cd ${DESTDIR}${GCC_ARCHDIR}/include && ${RM} -f fixed && ${RMDIR} v7 v9
.else
post-install:
.  if exists(/usr/include/g++/FlexLexer.h)
	${LN} -fs /usr/include/g++/FlexLexer.h				\
		${DESTDIR}${GCC_PREFIX}/include/g++-3/FlexLexer.h
.  endif
	${RM} -f ${DESTDIR}${GCC_ARCHDIR}/include/curses.h ${DESTDIR}${GCC_PREFIX}/bin/cc
.endif
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/${DISTNAME}
	${INSTALL_DATA} ${WRKDIR}/gcc.mk ${DESTDIR}${PREFIX}/share/examples/${DISTNAME}/mk.conf
	${LN} -s gcc ${DESTDIR}${GCC_PREFIX}/bin/cc

.include "../../mk/bsd.pkg.mk"

# Make bootstrap with compiler != gcc possible.
LDFLAGS=		${_STRIPFLAG_CC}
