# $NetBSD: Makefile,v 1.59 2006/08/24 13:25:41 wennmach Exp $

DISTNAME=		arla-0.43
#PKGREVISION=		1
CATEGORIES=		net security
MASTER_SITES=		ftp://ftp.stacken.kth.se/pub/arla/

MAINTAINER=		wennmach@NetBSD.org
HOMEPAGE=		http://www.stacken.kth.se/project/arla/
COMMENT=		Free AFS implementation from KTH

CONFLICTS+=		heimdal-[0-9]*
CONFLICTS+=		lwp-[0-9]*
CONFLICTS+=		openafs-[0-9]*
CONFLICTS+=		rx-[0-9]*
CONFLICTS+=		kth-krb4-[0-9]*

OSVERSION_SPECIFIC=	yes
INFO_FILES=		# PLIST

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if !exists(/usr/src/sys/lib/libkern/libkern.h)
.  if exists(${BSDSRCDIR}/sys/lib/libkern/libkern.h)
CONFIGURE_ARGS+=	--with-sys=${BSDSRCDIR}/sys
.  else
PKG_FAIL_REASON+=	"${PKGNAME} requires kernel sources available under \$$BSDSRCDIR/sys (or /usr/src/sys)"
.  endif
.endif

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-arlacachedir=${ARLA_CACHE:Q}
CONFIGURE_ARGS+=	--enable-shared=no

# Enable one or more of the following kernel compile options as required:
# (these options must match the compile options of the kernel)
#CONFIGURE_ENV+=	KERNEL_CPPFLAGS="-DMULTIPROCESSOR -DDEBUG -DDIAGNOSTIC"

MESSAGE_SUBST+=		ARLA_CACHE=${ARLA_CACHE:Q}
PLIST_SUBST+=		ARLA_CACHE=${ARLA_CACHE:Q}
FILES_SUBST+=		ARLA_CACHE=${ARLA_CACHE:Q}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/lkm.conf
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_STAGE.paths=	post-patch

INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS}
INSTALL_MAKE_FLAGS+=	lkmdir=${PREFIX:Q}/lkm
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR:Q}

EGDIR=		${PREFIX}/share/examples/arla
EGFILES=	CellServDB DynRootDB SuidCells ThisCell arla.conf

.for f in ${EGFILES}
CONF_FILES+=    ${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

RCD_SCRIPTS=	arlad
OWN_DIRS_PERMS=	${ARLA_CACHE} ${ROOT_USER} ${ROOT_GROUP} 0700

.include "../../mk/x11.buildlink3.mk"

post-extract:
	${CP} ${FILESDIR}/lkm.conf ${WRKDIR}/lkm.conf

post-install:
	${RM} -f ${EGDIR}/*.default
	${INSTALL_DATA} ${WRKDIR}/lkm.conf ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/fstab ${EGDIR}

.include "../../mk/bsd.pkg.mk"
