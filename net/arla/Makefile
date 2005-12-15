# $NetBSD: Makefile,v 1.48 2005/12/15 21:28:47 wennmach Exp $

DISTNAME=		arla-0.41
#PKGREVISION=		1
CATEGORIES=		net security
MASTER_SITES=		ftp://ftp.stacken.kth.se/pub/arla/

MAINTAINER=		wennmach@NetBSD.org
HOMEPAGE=		http://www.stacken.kth.se/project/arla/
COMMENT=		Free AFS implementation from KTH

CONFLICTS+=		lwp-[0-9]*
CONFLICTS+=		rx-[0-9]*

OSVERSION_SPECIFIC=	yes
INFO_FILES=		arla.info send-pr.info

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

.include "../../mk/bsd.prefs.mk"

.if !exists(/usr/src/sys/lib/libkern/libkern.h)
.  if exists(${BSDSRCDIR}/sys/lib/libkern/libkern.h)
CONFIGURE_ARGS+=	--with-sys=${BSDSRCDIR}/sys
.  else
PKG_FAIL_REASON+=	"${PKGNAME} requires kernel sources available under \$$BSDSRCDIR/sys (or //usr/src/sys)"
.  endif
.endif

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-arlacachedir=${ARLA_CACHE:Q}
CONFIGURE_ARGS+=	--enable-shared=no

# Enable one or more of the following kernel compile options as required:
# (these options must match the compile options of the kernel)
#CONFIGURE_ENV+=	KERNEL_CPPFLAGS="-DMULTIPROCESSOR -DDEBUG -DDIAGNOSTIC"

MESSAGE_SUBST+=		ARLA_CACHE=${ARLA_CACHE}
PLIST_SUBST+=		ARLA_CACHE=${ARLA_CACHE:Q}
FILES_SUBST+=		ARLA_CACHE=${ARLA_CACHE:Q}

EGDIR=		${PREFIX}/share/examples/arla

EGFILES=	CellServDB DynRootDB SuidCells ThisCell arla.conf

.for f in ${EGFILES}
CONF_FILES+=    ${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

RCD_SCRIPTS=	arlad
OWN_DIRS_PERMS=	${ARLA_CACHE} ${ROOT_USER} ${ROOT_GROUP} 0700

INSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL
DEINSTALL_EXTRA_TMPL=	${.CURDIR}/DEINSTALL

.include "../../mk/x11.buildlink3.mk"

post-install:
	${RM} -f ${EGDIR}/*.default
	${SED}	${FILES_SUBST_SED}					\
		< ${FILESDIR}/lkm.conf > ${WRKDIR}/lkm.conf
	${INSTALL_DATA} ${WRKDIR}/lkm.conf ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/fstab ${EGDIR}

.include "../../mk/bsd.pkg.mk"
