# $NetBSD: Makefile,v 1.18 1999/03/08 10:53:57 agc Exp $
# FreeBSD Id: Makefile,v 1.21 1997/08/13 23:29:52 jmz Exp
#

DISTNAME=	ispell-3.1.20
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cs.ucla.edu/pub/ispell-3.1/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/ispell/ispell.html

WRKSRC=		${WRKDIR}/ispell-3.1

MAKE_FLAGS=	TMPDIR=${WRKDIR}
SCRIPTS_ENV=	"LANG=${ISPELL_LANG}"

USE_GTEXINFO=	yes
INFO_FILES=	ispell.info

.if exists(/usr/include/inttypes.h)
CFLAGS+=	-DHAVE_INTTYPES_H
.endif

.include "../../mk/bsd.prefs.mk"

.ifdef ISPELL_FR
EXTRA_DICT=	francais-IREQ-1.4.tar.gz
MASTER_SITES+=	ftp://ftp.robot.ireq.ca/pub/ispell/
DISTFILES+=	${EXTRA_DICT}
.endif

pre-extract:
.ifndef ISPELL_LANG
	@${ECHO} '*******************************************************'
	@${ECHO} '* Note that you can build a british version by        *'
	@${ECHO} '* typing "${MAKE} british" following a "${MAKE} clean"*'
	@${ECHO} '* Note that you can build a french/english version    *'
	@${ECHO} '* by typing "${MAKE} french"                          *'
	@${ECHO} '*******************************************************'
.endif

pre-configure:
.if defined(EXTRA_DICT)
	@${ECHO} ${EXTRA_DICT} > ${WRKDIR}/extra_dict
.endif

post-configure:
	@${ECHO} "#define CFLAGS \"${CFLAGS}\"" >> ${WRKSRC}/local.h

british:
	@${ECHO} "Okay, making a british version of ispell...."
	@${MAKE} ${.MAKEFLAGS} ISPELL_LANG=british all

french:
	@${ECHO} "Okay, making a french/english version of ispell...."
	@${MAKE} ${.MAKEFLAGS} ISPELL_FR=yes

pre-install:
	@${MKDIR} ${PREFIX}/share/emacs/site-lisp

.include "../../mk/bsd.pkg.mk"
