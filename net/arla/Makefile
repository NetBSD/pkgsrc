# $NetBSD: Makefile,v 1.22 2002/07/12 20:40:31 wiz Exp $
#

DISTNAME=		arla-0.35.8
CATEGORIES=		net security
MASTER_SITES=		ftp://ftp.stacken.kth.se/pub/arla/

MAINTAINER=		wennmach@netbsd.org
HOMEPAGE=		http://www.stacken.kth.se/project/arla/
COMMENT=		Free AFS implementation from KTH

.if exists(/usr/lib/libroken.a)
CONFIGURE_ARGS+=	--with-krb4-lib=/usr
CONFIGURE_ARGS+=	--with-krb4-include=/usr/include/kerberosIV
CONFIGURE_ARGS+=	--with-roken=/usr
CONFIGURE_ARGS+=	--with-roken-include=/usr/include/krb5
.else
.include "../../security/kth-krb4/buildlink.mk"
USE_BUILDLINK_ONLY=	# defined
CONFIGURE_ARGS+=	--with-krb4-lib=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-krb4-include=${BUILDLINK_DIR}/include
CONFIGURE_ARGS+=	--with-roken=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-roken-include=${BUILDLINK_DIR}/include/kerberosIV
.endif

# for "amon":
.include "../../mk/x11.buildlink.mk"

CONFLICTS+=		lwp-[0-9]*
CONFLICTS+=		rx-[0-9]*

OSVERSION_SPECIFIC=	yes
GNU_CONFIGURE=		yes
INFO_FILES=		arla.info

.include "../../mk/bsd.prefs.mk"

.if !exists(/sys/lib/libkern/libkern.h)
.if exists(${BSDSRCDIR}/sys/lib/libkern/libkern.h)
CONFIGURE_ARGS+=	--with-sys=${BSDSRCDIR}/sys
.else
IGNORE=			"${PKGNAME} requires kernel sources available under \$$BSDSRCDIR/sys (or /sys)"
.endif
.endif

.if defined(ARLA_CACHE)
CONFIGURE_ARGS+=	--with-arlacachedir=${ARLA_CACHE}
.endif

.if defined(ARLA_CACHE)
CACHEDIR=		${ARLA_CACHE}
.else
CACHEDIR=		${LOCALBASE}/cache
.endif
MESSAGE_SUBST+=		ARLA_CACHE=${CACHEDIR}
PLIST_SUBST+=		ARLA_CACHE=${CACHEDIR}

do-configure:
# *Sometimes* it's bad to try to be too smart:
# pkgsrc's LDFLAGS choice is completely inadequate for arla, since
# arla's configure uses $LDFLAGS as flags for $LD, whereas
# pkgsrc's LDFLAGS are conceived to be used with $CC
# So, basically, bsd.pkg.mk sets LDFLAGS=-Wl,-R${LOCALBASE}
# while arla expects LDFLAGS=-R${LOCALBASE}
	@(LDFLAGS= ; cd ${WRKSRC}; ./configure ${CONFIGURE_ARGS})

post-install:
	@${ECHO} " "
	@if [ -e ${CACHEDIR} ]; then                                          \
		${ECHO} "Arla cache dir (${CACHEDIR}) already exists";        \
	else                                                                  \
		${ECHO} "Creating arla cache directory ${CACHEDIR}";          \
		${INSTALL_DATA_DIR} ${CACHEDIR};                              \
		${CHMOD} 700 ${CACHEDIR};                                     \
		${CHOWN} ${ROOT_USER} ${CACHEDIR};                            \
	fi
	@if [ -e /sbin/mount_xfs ]; then                                      \
		${ECHO} "/sbin/mount_xfs already exists";                     \
	else                                                                  \
		${ECHO} "Creating /sbin/mount_xfs";                           \
		${LN} -s ${PREFIX}/sbin/mount_xfs /sbin/mount_xfs;            \
	fi
	@-${INSTALL_DATA_DIR} ${PREFIX}/share/examples/arla
	@${SED} -e 's|@PREFIX@|${PREFIX}|g'                                   \
		< ${FILESDIR}/lkm.conf                                        \
		> ${PREFIX}/share/examples/arla/lkm.conf
	@${INSTALL_DATA}                                                      \
		${FILESDIR}/services ${PREFIX}/share/examples/arla
	@${INSTALL_DATA}                                                      \
		 ${FILESDIR}/fstab ${PREFIX}/share/examples/arla
	@${SED} -e 's|@PREFIX@|${PREFIX}|' ${FILESDIR}/arlad.sh               \
		> ${PREFIX}/etc/rc.d/arlad.sh
	@${SED} -e 's|@PREFIX@|${PREFIX}|' ${FILESDIR}/arlad                  \
		> ${PREFIX}/etc/rc.d/arlad
	@${ECHO} " "

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
