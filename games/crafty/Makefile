# $NetBSD: Makefile,v 1.34 2005/06/06 03:59:00 minskim Exp $

DISTNAME=		crafty-18.15
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.cis.uab.edu/pub/hyatt/v18/ \
			ftp://ftp.cis.uab.edu/pub/hyatt/ \
			ftp://ftp.cis.uab.edu/pub/hyatt/common/
DISTFILES=		${CRAFTY_DISTFILES}
DISTFILES+=		${CRAFTY_STARTPGN} ${CRAFTY_DOCFILES}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Chess engine


DIST_SUBDIR=		${DISTNAME}-1
CRAFTY_DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
CRAFTY_STARTPGN=	start.pgn
CRAFTY_DOCFILES=	read.me crafty.faq
EXTRACT_ONLY=		${CRAFTY_DISTFILES}

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386)
.  if ${OBJECT_FMT} == "ELF"
BUILD_TARGET=		netbsd-i386-elf
.  else
BUILD_TARGET=		netbsd-i386
.  endif
.elif !empty(MACHINE_PLATFORM:MNetBSD-*-sparc)
BUILD_TARGET=		netbsd-sparc
# higher levels of optimization cause crafty to immediately segfault
CFLAGS:=		${CFLAGS:C/-O[0-9]*/-O1/}
.elif !empty(MACHINE_PLATFORM:MNetBSD-*-*)
BUILD_TARGET=		netbsd
.elif !empty(MACHINE_PLATFORM:MLinux-*-i386)
.  if ${OBJECT_FMT} == "ELF"
BUILD_TARGET=		linux-elf
.  else
BUILD_TARGET=		linux
.  endif
.elif !empty(MACHINE_PLATFORM:MSunOS-*-*)
BUILD_TARGET=		solaris-gcc
.else
BUILD_TARGET=		generic
.endif

CRAFTY_OPTS=		-DBOOKDIR=\\\"${BOOKDIR}\\\"
CRAFTY_OPTS+=		-DTBDIR=\\\"${TBDIR}\\\"
MAKE_ENV+=		opt="${CRAFTY_OPTS}"

BOOKDIR=		${PREFIX}/lib/crafty
TBDIR=			${PREFIX}/share/egtb
DOCDIR=			${PREFIX}/share/doc/crafty

CRAFTYRC=		${WRKSRC}/.craftyrc

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${CRAFTY_STARTPGN} ${WRKSRC}
	${MV} ${WRKSRC}/Sparc.s ${WRKSRC}/Sparc.S

post-patch:
	cd ${WRKSRC}; for file in Makefile; do				\
		${SED}	-e "s| -O3||g" -e "s| -m486||g"			\
			$${file} >> $${file}.fixed;			\
		${MV} $${file}.fixed $${file};				\
	done

post-build:
	${RM} -f ${CRAFTYRC}
	${ECHO} "books create ${CRAFTY_STARTPGN} 60" > ${CRAFTYRC}
	${ECHO} "quit" >> ${CRAFTYRC}
	cd ${WRKSRC} && ${WRKSRC}/crafty bookpath=.

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/crafty ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${BOOKDIR}
	${INSTALL_DATA} ${WRKSRC}/books.bin ${BOOKDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	for file in ${CRAFTY_DOCFILES}; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$${file} ${DOCDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
