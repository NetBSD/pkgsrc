# $NetBSD: Makefile,v 1.49 2001/12/21 21:26:05 atatat Exp $
#

DISTNAME=		lsof_4.60_W
PKGNAME=		lsof-4.60
WRKSRC=			${WRKDIR}/${SRCBALL_NAME}
CATEGORIES=		sysutils
MASTER_SITES=		ftp://vic.cc.purdue.edu/pub/tools/unix/lsof/  \
			ftp://vic.cc.purdue.edu/pub/tools/unix/lsof/NEW/ \
			ftp://ftp.cert.dfn.de/pub/tools/admin/lsof/  \
			ftp://ftp.auscert.org.au/pub/mirrors/vic.cc.purdue.edu/lsof/  \
			ftp://ftp.web.ad.jp/pub/UNIX/tools/lsof/  \
			ftp://ftp0.sunet.se/pub/unix/admin/lsof/

MAINTAINER=		wiz@netbsd.org
HOMEPAGE=		http://www-rcd.cc.purdue.edu/~abe/
COMMENT=		Lists information about open files

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS=		-n ${LOWER_OPSYS}
CONFIGURE_ENV+=		LSOF_CC="${CC} ${CFLAGS}"
MAKE_FLAGS+=		LSOF_BLDCMT="NetBSD pkgsrc rocks!"
CPPFLAGS+=		-DLSOF_MORE_SECURE=${LSOF_MORE_SECURE}

SRCBALL_NAME=		${DISTNAME:S/_W$//}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
REAL_GROUP=		-g kmem
.elif ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=
.endif

LSOF_MORE_SECURE?= 0

post-extract:
	@(cd ${WRKDIR} ; \
	EXPMD5=`${GREP} MD5 README.${SRCBALL_NAME} | ${SED} 's/^[ ]*//'` ; \
	CALCMD5=`${DIGEST} MD5 ${SRCBALL_NAME}.tar` ; \
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
	${INSTALL} ${COPY} ${STRIPFLAG} -o ${BINOWN} -g ${BINGRP} -m 2755 ${REAL_GROUP} \
		${WRKSRC}/lsof ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/lsof.man ${PREFIX}/man/man1/lsof.1
	@${INSTALL_DATA_DIR} ${PREFIX}/share/lsof
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${PREFIX}/share/lsof
	@${CHMOD} 0444 ${PREFIX}/share/lsof/00*

.include "../../mk/bsd.pkg.mk"
