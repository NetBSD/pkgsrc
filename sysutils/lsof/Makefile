# $NetBSD: Makefile,v 1.95 2008/04/26 11:54:24 apb Exp $

DISTNAME=		lsof_4.78
PKGNAME=		${DISTNAME:S/_/-/}.${OS_VERSION}
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		ftp://lsof.itap.purdue.edu/pub/tools/unix/lsof/  \
			ftp://lsof.itap.purdue.edu/pub/tools/unix/lsof/NEW/ \
			ftp://lsof.itap.purdue.edu/pub/tools/unix/lsof/OLD/ \
			ftp://ftp.sunet.se/pub/unix/admin/lsof/ \
			http://ftp.sunet.se/pub/unix/admin/lsof/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		atatat@NetBSD.org
HOMEPAGE=		http://people.freebsd.org/~abe/
COMMENT=		Lists information about open files

WRKSRC=			${WRKDIR}/${DISTNAME}/${SRCBALL_NAME}
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-n ${LOWER_OPSYS}
CONFIGURE_ENV+=		LSOF_CC="${CC} ${CFLAGS}"
MAKE_FLAGS+=		LSOF_BLDCMT="NetBSD pkgsrc rocks!"
CPPFLAGS+=		-DLSOF_MORE_SECURE=${LSOF_MORE_SECURE} \
			-DLSOF_LESS_SECURE_SOCKETS=${LSOF_LESS_SECURE_SOCKETS}
OSVERSION_SPECIFIC=	yes

TMPWRK=			${WRKDIR}/${DISTNAME}
SRCBALL_NAME=		${DISTNAME}_src

REPLACE_PERL+=	scripts/sort_res.perl5 scripts/count_pf.perl5 \
		scripts/list_NULf.perl5 scripts/big_brother.perl5 \
		scripts/identd.perl5 scripts/shared.perl5 \
		scripts/idrlogin.perl5 scripts/count_pf.perl \
		scripts/idrlogin.perl scripts/list_fields.perl \
		scripts/watch_a_file.perl
USE_TOOLS+=	gtar perl:run

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
REAL_GROUP=		-g kmem
CONFIGURE_ENV+=		NETBSD_SYS="${NETBSDSRCDIR}/sys"
.elif ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=
.endif
INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

LSOF_MORE_SECURE?= 0

post-extract:
	@(cd ${TMPWRK} ; \
	EXPMD5=`${GREP} 'MD5 (' README.${DISTNAME} | ${SED} 's/^[ ]*//'` ; \
	CALCMD5=`${DIGEST} MD5 ${SRCBALL_NAME}.tar` ; \
	if [ "$${EXPMD5}"X != "$${CALCMD5}"X ]; then \
		${ECHO} "Expected and calculated MD5 signatures don't agree." ; \
		${ECHO} "($$EXPMD5 != $$CALCMD5)" ; \
		exit 1 ; \
	fi ; \
	if [ X${EXTRACT_USING} = Xgtar ]; then \
		${GTAR} -xf ${SRCBALL_NAME}.tar; \
	else \
		${PAX} -O -r < ${SRCBALL_NAME}.tar; \
	fi)
	@( cd ${WRKSRC} ; ${ECHO} "y" | ./Inventory || exit 1 )

do-install:
	${INSTALL} ${COPY} ${_STRIPFLAG_INSTALL} -o ${BINOWN} -g ${BINGRP} -m 2755 ${REAL_GROUP} \
		${WRKSRC}/lsof ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/lsof.8 ${PREFIX}/${PKGMANDIR}/man8/lsof.8
	@${INSTALL_DATA_DIR} ${PREFIX}/share/lsof
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${PREFIX}/share/lsof
	@${CHMOD} 0444 ${PREFIX}/share/lsof/00*

.include "../../mk/bsd.pkg.mk"
