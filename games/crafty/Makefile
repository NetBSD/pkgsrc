# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 02:06:27 jlam Exp $

DISTNAME=		crafty-17.13
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.cis.uab.edu/pub/hyatt/ \
			ftp://ftp.cis.uab.edu/pub/hyatt/common/ \
			ftp://ftp.cis.uab.edu/pub/hyatt/v17/
DISTFILES=		${CRAFTY_DISTFILES}
DISTFILES+=		${CRAFTY_STARTPGN} ${CRAFTY_DOCFILES}

MAINTAINER=		jlam@netbsd.org

DIST_SUBDIR=		${DISTNAME}
NO_WRKSUBDIR=		# defined
CRAFTY_DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
CRAFTY_STARTPGN=	start.pgn
CRAFTY_DOCFILES=	read.me crafty.faq
EXTRACT_ONLY=		${CRAFTY_DISTFILES}

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
.if ${OBJECT_FMT} == "ELF"
ALL_TARGET=		netbsd-i386-elf
.else
ALL_TARGET=		netbsd-i386
.endif
.elif ${MACHINE_ARCH} == "sparc"
ALL_TARGET=		netbsd-sparc
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
	for file in ${DISTFILES}; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$${file} ${DOCDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
