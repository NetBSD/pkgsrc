# $NetBSD: Makefile,v 1.27 2004/04/24 22:46:10 jlam Exp $

DISTNAME=		crafty-18.15
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.cis.uab.edu/pub/hyatt/v18/ \
			ftp://ftp.cis.uab.edu/pub/hyatt/ \
			ftp://ftp.cis.uab.edu/pub/hyatt/common/
DISTFILES=		${CRAFTY_DISTFILES}
DISTFILES+=		${CRAFTY_STARTPGN} ${CRAFTY_DOCFILES}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Chess engine

USE_BUILDLINK3=		YES

WRKSRC=			${WRKDIR}
DIST_SUBDIR=		${DISTNAME}
CRAFTY_DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
CRAFTY_STARTPGN=	start.pgn
CRAFTY_DOCFILES=	read.me crafty.faq
EXTRACT_ONLY=		${CRAFTY_DISTFILES}

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386)
.  if ${OBJECT_FMT} == "ELF"
ALL_TARGET=		netbsd-i386-elf
.  else
ALL_TARGET=		netbsd-i386
.  endif
.elif !empty(MACHINE_PLATFORM:MNetBSD-*-sparc)
ALL_TARGET=		netbsd-sparc
# higher levels of optimization cause crafty to immediately segfault
CFLAGS:=		${CFLAGS:C/-O[0-9]*/-O1/}
.elif !empty(MACHINE_PLATFORM:MNetBSD-*-*)
ALL_TARGET=		netbsd
.elif !empty(MACHINE_PLATFORM:MSunOS-*-*)
ALL_TARGET=		solaris-gcc
.else
ALL_TARGET=		generic
.endif

CRAFTY_OPTS=		-DBOOKDIR=\\\"${BOOKDIR}\\\"
CRAFTY_OPTS+=		-DTBDIR=\\\"${TBDIR}\\\"
MAKE_ENV+=		opt="${CRAFTY_OPTS}"

BOOKDIR=		${PREFIX}/lib/crafty
TBDIR=			${PREFIX}/share/egtb
DOCDIR=			${PREFIX}/share/doc/crafty

CRAFTYRC=		${WRKDIR}/.craftyrc

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${CRAFTY_STARTPGN} ${WRKDIR}
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
	${INSTALL_DATA} ${WRKDIR}/books.bin ${BOOKDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	for file in ${CRAFTY_DOCFILES}; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$${file} ${DOCDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
