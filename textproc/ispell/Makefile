# $NetBSD: Makefile,v 1.15 1998/12/21 00:35:59 frueauf Exp $
# FreeBSD Id: Makefile,v 1.21 1997/08/13 23:29:52 jmz Exp
#

DISTNAME=	ispell-3.1.20
WRKSRC=		${WRKDIR}/ispell-3.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cs.ucla.edu/pub/ispell-3.1/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/ispell/ispell.html

MAKE_FLAGS=	TMPDIR=${WRKDIR}
SCRIPTS_ENV=	"LANG=${LANG}"

USE_GTEXINFO=	yes
INFO_FILES=	ispell.info

.include "../../mk/bsd.prefs.mk"

_INTTYPES!=	if [ -e /usr/include/inttypes.h ]; then echo "Exists"; else echo "No go"; fi

.if (${_INTTYPES} == "Exists")
CFLAGS+= -DHAVE_INTTYPES_H
.endif

pre-extract pre-build pre-install:
.if !defined(ISPELL_FR)
	@echo '******************************************************'
	@echo '* Note that you can build a french/english version   *'
	@echo '* by typing "make french"                            *'
	@echo '******************************************************'
.else
EXTRA_DICT=	francais-IREQ-1.4.tar.gz
MASTER_SITES+=	ftp://ftp.robot.ireq.ca/pub/ispell/
DISTFILES+=	${EXTRA_DICT}
.endif

pre-extract:
.if !defined(LANG)
	@echo '******************************************************'
	@echo '* Note that you can build a british version by       *'
	@echo '* typing "make british" following a "make clean"     *'
	@echo '******************************************************'
.endif

pre-configure:
.if defined(EXTRA_DICT)
	@echo ${EXTRA_DICT} > ${WRKDIR}/extra_dict
.else
	@echo -n
.endif

post-configure:
	@echo "#define CFLAGS \"${CFLAGS}\"" >> ${WRKSRC}/local.h

british:
	@echo "Okay, making a british version of ispell...."
	@${MAKE} ${.MAKEFLAGS} LANG=british all

french:
	@echo "Okay, making a french/english version of ispell...."
	@${MAKE} ${.MAKEFLAGS} ISPELL_FR=yes

pre-install:
	@${MKDIR} ${PREFIX}/share/emacs/site-lisp

.include "../../mk/bsd.pkg.mk"
