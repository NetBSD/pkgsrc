# $NetBSD: Makefile,v 1.142 2022/06/28 11:35:58 wiz Exp $

DISTNAME=		lsof_4.91
PKGNAME=		${DISTNAME:S/_/-/}
PKGREVISION=		7
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.mirrorservice.org/sites/lsof.itap.purdue.edu/pub/tools/unix/lsof/
MASTER_SITES+=		ftp://ftp.mirrorservice.org/sites/lsof.itap.purdue.edu/pub/tools/unix/lsof/OLD/
MASTER_SITES+=		ftp://ftp.fu-berlin.de/pub/unix/tools/lsof/
MASTER_SITES+=		ftp://ftp.fu-berlin.de/pub/unix/tools/lsof/OLD/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://people.freebsd.org/~abe/
COMMENT=		Lists information about open files
LICENSE=		purdue

WRKSRC=			${WRKDIR}/${DISTNAME}/${SRCBALL_NAME}
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-n ${LOWER_OPSYS}
CONFIGURE_ENV+=		LSOF_CC="${CC} ${CFLAGS} ${LDFLAGS}"
MAKE_FLAGS+=		LSOF_BLDCMT="NetBSD pkgsrc rocks!"
OSVERSION_SPECIFIC=	yes
EXTRACT_USING=		bsdtar

TMPWRK=			${WRKDIR}/${DISTNAME}
SRCBALL_NAME=		${DISTNAME}_src

REPLACE_PERL+=	scripts/sort_res.perl5 scripts/count_pf.perl5 \
		scripts/list_NULf.perl5 scripts/big_brother.perl5 \
		scripts/identd.perl5 scripts/shared.perl5 \
		scripts/idrlogin.perl5 scripts/count_pf.perl \
		scripts/idrlogin.perl scripts/list_fields.perl \
		scripts/watch_a_file.perl
REPLACE_AWK+=	scripts/xusers.awk
USE_TOOLS+=	digest perl:run

TEST_DIRS=		tests
TEST_TARGET=		test
INTERACTIVE_STAGE+=	test

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

REAL_GROUP=			${REAL_ROOT_GROUP}
.if ${OPSYS} == "NetBSD"
REAL_GROUP=			kmem
CONFIGURE_ENV+=			NETBSD_SYS="${NETBSDSRCDIR}/sys"
CPPFLAGS+=			-D_KMEMUSER -D__NAMECACHE_PRIVATE
.elif ${OPSYS} == "FreeBSD"
BUILDLINK_PASSTHRU_DIRS+=	/usr/src/sys
.elif ${OPSYS} == "SunOS"
REAL_GROUP=			sys
MAKE_ENV+=			CPPFLAGS=
CONFIGURE_ENV+=			LSOF_RANLIB="/bin/true"
.endif
INSTALLATION_DIRS+=		sbin ${PKGMANDIR}/man8 share/doc/lsof share/examples/lsof

post-extract:
.if ${OPSYS} == "FreeBSD"
	if [ ! -x /usr/src/sys ]; then \
		${ECHO} "Lsof requires kernel sources to be found in /usr/src/sys." ; \
		exit 1 ; \
	fi
.endif
	cd ${TMPWRK} ; \
	EXPMD5=`${GREP} 'MD5 (' README.${DISTNAME} | ${SED} 's/^[ ]*//'` ; \
	CALCMD5=`${DIGEST} MD5 ${SRCBALL_NAME}.tar` ; \
	if [ "$${EXPMD5}"X != "$${CALCMD5}"X ]; then \
		${ECHO} "Expected and calculated MD5 signatures don't agree." ; \
		${ECHO} "($$EXPMD5 != $$CALCMD5)" ; \
		exit 1 ; \
	fi ; \
	${TOOLS_PATH.bsdtar} -xf ${SRCBALL_NAME}.tar
	cd ${WRKSRC} ; ${ECHO} "y" | ./Inventory || exit 1
	${CP} ${FILESDIR}/rnmt.c ${WRKSRC}/lib/rnmt.c

SPECIAL_PERMS+=		${PREFIX}/sbin/lsof ${REAL_ROOT_USER} ${REAL_GROUP} 2755

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lsof ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/lsof.8 \
	  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/lsof.8
	${INSTALL_DATA} ${WRKSRC}/00* ${DESTDIR}${PREFIX}/share/doc/lsof
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DESTDIR}${PREFIX}/share/doc/lsof
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.perl* \
	  ${DESTDIR}${PREFIX}/share/examples/lsof
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/xusers.awk \
	  ${DESTDIR}${PREFIX}/share/examples/lsof
	${INSTALL_DATA} ${WRKSRC}/scripts/list_fields.awk \
	  ${DESTDIR}${PREFIX}/share/examples/lsof
	${INSTALL_DATA} ${WRKSRC}/scripts/00* \
	  ${DESTDIR}${PREFIX}/share/examples/lsof

.PHONY: opt
opt:
.for dir in ${TEST_DIRS}
	${RUN}${_ULIMIT_CMD}			\
	cd ${WRKSRC} && cd ${dir} &&		\
	${TEST_MAKE_CMD} opt
.endfor
.include "../../mk/bsd.pkg.mk"
