# $NetBSD: Makefile,v 1.39 2004/10/03 00:17:49 tv Exp $

DISTNAME=		arla-0.35.12
PKGREVISION=	1
#PKGREVISION=
CATEGORIES=		net security
MASTER_SITES=		ftp://ftp.stacken.kth.se/pub/arla/

MAINTAINER=		wennmach@NetBSD.org
HOMEPAGE=		http://www.stacken.kth.se/project/arla/
COMMENT=		Free AFS implementation from KTH

CONFLICTS+=		lwp-[0-9]*
CONFLICTS+=		rx-[0-9]*

OSVERSION_SPECIFIC=	yes
INFO_FILES=		arla.info

USE_BUILDLINK3=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

.if exists(/usr/lib/libroken.a)
CONFIGURE_ARGS+=	--with-krb4-lib=/usr/lib
CONFIGURE_ARGS+=	--with-krb4-include=/usr/include/kerberosIV
CONFIGURE_ARGS+=	--with-roken=/usr
CONFIGURE_ARGS+=	--with-roken-include=/usr/include/krb5
.else
.  include "../../security/kth-krb4/buildlink3.mk"
CONFIGURE_ARGS+=	--with-krb4-lib=${BUILDLINK_PREFIX.kth-krb4}
CONFIGURE_ARGS+=	--with-krb4-include=${BUILDLINK_PREFIX.kth-krb4}/include
CONFIGURE_ARGS+=	--with-roken=${BUILDLINK_PREFIX.kth-krb4}
CONFIGURE_ARGS+=	--with-roken-include=${BUILDLINK_PREFIX.kth-krb4}/include/kerberosIV
.endif

.include "../../mk/bsd.prefs.mk"

.if !exists(/sys/lib/libkern/libkern.h)
.  if exists(${BSDSRCDIR}/sys/lib/libkern/libkern.h)
CONFIGURE_ARGS+=	--with-sys=${BSDSRCDIR}/sys
.  else
PKG_FAIL_REASON= "${PKGNAME} requires kernel sources available under \$$BSDSRCDIR/sys (or /sys)"
.  endif
.endif

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-arlacachedir=${ARLA_CACHE}
MESSAGE_SUBST+=		ARLA_CACHE=${ARLA_CACHE}
PLIST_SUBST+=		ARLA_CACHE=${ARLA_CACHE}
FILES_SUBST+=		ARLA_CACHE=${ARLA_CACHE}

EGDIR=		${PREFIX}/share/examples/arla
RCD_SCRIPTS=	arlad

CONF_FILES=	${EGDIR}/CellServDB ${PKG_SYSCONFDIR}/CellServDB
CONF_FILES+=	${EGDIR}/SuidCells ${PKG_SYSCONFDIR}/SuidCells
CONF_FILES+=	${EGDIR}/ThisCell ${PKG_SYSCONFDIR}/ThisCell
CONF_FILES+=	${EGDIR}/arla.conf ${PKG_SYSCONFDIR}/arla.conf
OWN_DIRS_PERMS=	${ARLA_CACHE} ${ROOT_USER} ${ROOT_GROUP} 0700

INSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL
DEINSTALL_EXTRA_TMPL=	${.CURDIR}/DEINSTALL

post-install:
	${RM} -f ${EGDIR}/*.default
	${SED}	${FILES_SUBST_SED}					\
		< ${FILESDIR}/lkm.conf > ${WRKDIR}/lkm.conf
	${INSTALL_DATA} ${WRKDIR}/lkm.conf ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/services ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/fstab ${EGDIR}

.include "../../mk/bsd.pkg.mk"
