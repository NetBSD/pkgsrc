# $NetBSD: Makefile,v 1.16 1999/02/21 21:25:03 agc Exp $
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

.include "../../mk/bsd.prefs.mk"

_INTTYPES!=	if [ -e /usr/include/inttypes.h ]; then ${ECHO} "Exists"; else ${ECHO} "No go"; fi

.if (${_INTTYPES} == "Exists")
CFLAGS+= -DHAVE_INTTYPES_H
.endif

pre-extract pre-build pre-install:
.if !defined(ISPELL_FR)
	@${ECHO} '******************************************************'
	@${ECHO} '* Note that you can build a french/english version   *'
	@${ECHO} '* by typing "make french"                            *'
	@${ECHO} '******************************************************'
.else
EXTRA_DICT=	francais-IREQ-1.4.tar.gz
MASTER_SITES+=	ftp://ftp.robot.ireq.ca/pub/ispell/
DISTFILES+=	${EXTRA_DICT}
.endif

pre-extract:
.if !defined(ISPELL_LANG)
	@${ECHO} '******************************************************'
	@${ECHO} '* Note that you can build a british version by       *'
	@${ECHO} '* typing "make british" following a "make clean"     *'
	@${ECHO} '******************************************************'
.endif

pre-configure:
.if defined(EXTRA_DICT)
	@${ECHO} ${EXTRA_DICT} > ${WRKDIR}/extra_dict
.else
	@${ECHO} -n
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
