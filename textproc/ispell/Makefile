# $NetBSD: Makefile,v 1.9 1998/06/10 08:02:09 agc Exp $
# FreeBSD Id: Makefile,v 1.21 1997/08/13 23:29:52 jmz Exp
#

DISTNAME=	ispell-3.1.20
WRKSRC=		${WRKDIR}/ispell-3.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cs.ucla.edu/pub/ispell-3.1/

MAINTAINER=	packages@netbsd.org

MAKE_FLAGS=	TMPDIR=${.CURDIR}
SCRIPTS_ENV=	"LANG=${LANG}"

MAN1=		buildhash.1 findaffix.1 ispell.1 munchlist.1 \
		sq.1 tryaffix.1 unsq.1
MAN4=		ispell.4 english.4

.include "../../mk/bsd.prefs.mk"

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
