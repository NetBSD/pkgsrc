# $NetBSD: Makefile,v 1.103 2010/03/21 16:29:43 wiz Exp $

DISTNAME=		lsof_4.78
PKGNAME=		${DISTNAME:S/_/-/}.${OS_VERSION}
PKGREVISION=		5
CATEGORIES=		sysutils
MASTER_SITES=		ftp://lsof.itap.purdue.edu/pub/tools/unix/lsof/  \
			ftp://lsof.itap.purdue.edu/pub/tools/unix/lsof/NEW/ \
			ftp://lsof.itap.purdue.edu/pub/tools/unix/lsof/OLD/ \
			ftp://ftp.sunet.se/pub/unix/admin/lsof/ \
			http://ftp.sunet.se/pub/unix/admin/lsof/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://people.freebsd.org/~abe/
COMMENT=		Lists information about open files

PKG_DESTDIR_SUPPORT=	user-destdir

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
USE_TOOLS+=	gtar pax perl:run

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

REAL_GROUP=		${REAL_ROOT_GROUP}
.if ${OPSYS} == "NetBSD"
REAL_GROUP=		kmem
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
		pax -O -r < ${SRCBALL_NAME}.tar; \
	fi)
	@( cd ${WRKSRC} ; ${ECHO} "y" | ./Inventory || exit 1 )

INSTALLATION_DIRS+=	sbin ${PKGMANDIR}/man8 share/lsof
SPECIAL_PERMS+=		${PREFIX}/sbin/lsof ${REAL_ROOT_USER} ${REAL_GROUP} 2755

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lsof ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/lsof.8 \
	  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/lsof.8
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${DESTDIR}${PREFIX}/share/lsof
	@${CHMOD} 0444 ${DESTDIR}${PREFIX}/share/lsof/00*

.include "../../mk/bsd.pkg.mk"
