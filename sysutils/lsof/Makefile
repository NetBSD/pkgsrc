# $NetBSD: Makefile,v 1.23 1999/07/30 21:56:57 tron Exp $
# FreeBSD Id: Makefile,v 1.19 1998/03/08 06:44:48 obrien Exp
#

DISTNAME=		lsof_4.45_W
PKGNAME=		lsof-4.45
WRKSRC=			${WRKDIR}/${SRCBALL_NAME}
CATEGORIES=		sysutils
MASTER_SITES=		ftp://vic.cc.purdue.edu/pub/tools/unix/lsof/  \
			ftp://ftp.cert.dfn.de/pub/tools/admin/lsof/  \
			ftp://ftp.auscert.org.au/pub/mirrors/vic.cc.purdue.edu/lsof/  \
			ftp://ftp.web.ad.jp/pub/UNIX/tools/lsof/  \
			ftp://ftp0.sunet.se/pub/unix/admin/lsof/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www-rcd.cc.purdue.edu/~abe/

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=		-n ${LOWER_OPSYS}

SRCBALL_NAME=		${DISTNAME:S/_W$//}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
REAL_GROUP=		-g kmem
.elif ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=
.endif

post-extract:
	@(cd ${WRKDIR} ; \
	EXPMD5=`${GREP} MD5 README.${SRCBALL_NAME} | ${SED} 's/^[ ]*//'` ; \
	CALCMD5=`${MD5} ${SRCBALL_NAME}.tar` ; \
	if [ "$${EXPMD5}"X != "$${CALCMD5}"X ]; then \
		${ECHO} "Expected and calculated MD5 signatures don't agree." ; \
		${ECHO} "($$EXPMD5 != $$CALCMD5)" ; \
		${FALSE} ; \
	fi ; \
	if [ "X${EXTRACT_USING_PAX}" = "X" ]; then \
		${GTAR} -xf ${SRCBALL_NAME}.tar; \
	else \
		${PAX} -r < ${SRCBALL_NAME}.tar; \
	fi)
	@( cd ${WRKSRC} ; ${ECHO} "y" | ./Inventory || exit 1 )

do-install:
	${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g ${BINGRP} -m 2755 ${REAL_GROUP} \
		${WRKSRC}/lsof ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/lsof.man ${PREFIX}/man/man1/lsof.1
	@${MKDIR} ${PREFIX}/share/lsof
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${PREFIX}/share/lsof
	@chmod 0444 ${PREFIX}/share/lsof/00*

.include "../../mk/bsd.pkg.mk"
