# $NetBSD: Makefile,v 1.13 1999/03/08 10:53:55 agc Exp $
# FreeBSD Id: Makefile,v 1.8 1997/06/13 16:17:01 ache Exp
#

DISTNAME=       rplay-3.2.0b6
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.sdsu.edu/pub/rplay/

MAINTAINER=	rmallory@csusb.edu

DEPENDS+=	gsm-1.0.10:../../audio/gsm

HAS_CONFIGURE=	yes
CONFIGURE_ARGS= "--prefix=${PREFIX}"
CONFIGURE_ENV+=        RPLAY_TARGET=generic # XXX
CONFIGURE_ENV+=        CFLAGS=-I${PREFIX}/include # XXX
CONFIGURE_ENV+=        LDFLAGS=-L${PREFIX}/lib # XXX
INFO_FILES=	RPTP.info RPLAY.info rplay.info librplay.info

pre-configure:
	for f in `find ${WRKDIR}/. -type f -print|xargs ${GREP} -l '/usr/local'`; do \
		${SED} -e 's:/usr/local:'${PREFIX}':g' < $$f > $$f.pdone && ${MV} $$f.pdone $$f; \
	done
	chmod +x ${WRKSRC}/configure

post-build:
	cd ${WRKSRC}/doc ; ${MAKE} info

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/rplayd.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/rplayd.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/rplayd.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/rplayd ] && ( ${PREFIX}/sbin/rplayd & ) && ${ECHO} -n ' rplayd'" >> ${PREFIX}/etc/rc.d/rplayd.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/rplayd.sh; \
	fi
	@if [ ! -f ${PREFIX}/etc/rplay.hosts ]; then \
		${ECHO} localhost > ${PREFIX}/etc/rplay.hosts; \
	fi

.include "../../mk/bsd.pkg.mk"
