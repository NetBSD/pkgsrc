# $NetBSD: Makefile,v 1.12 2001/01/29 11:34:34 wiz Exp $
#

DISTNAME=		arla-0.34.5
CATEGORIES=		net security
MASTER_SITES=		ftp://ftp.stacken.kth.se/pub/arla/

MAINTAINER=		wennmach@netbsd.org
HOMEPAGE=		http://www.stacken.kth.se/project/arla/

DEPENDS+=		kth-krb4-1.0.1:../../security/kth-krb4

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

CONFIGURE_ARGS+=	--with-krb4=${PREFIX}
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

post-patch:
# This is ugly. Utterly ugly. Sigh.
# kth-krb4 and arla both have their own, different, versions or libroken.
# To resolve this conflict, which manifests in the inability to recompile
# kth-krb4 once it is installed, we rename arla's roken to arla-roken.
	@${ECHO} "===> Applying more NetBSD patches for ${DISTNAME}"
	@${ECHO} -n "=> Patching configure,"
	@${MV} ${WRKSRC}/configure ${WRKSRC}/configure.old
# Notice, the following sed produces some funny comments in configure :-)
	@${SED} -e 's/roken/arla-roken/g' ${WRKSRC}/configure.old > ${WRKSRC}/configure
	@${CHMOD} 755 ${WRKSRC}/configure
	@${ECHO} -n " Makefile.in,"
	@for file in `${FIND} ${WRKSRC} -name Makefile.in -print`; {          \
		${MV} $$file $$file.old;                                      \
		${SED} -e 's/roken/arla-roken/g' $$file.old > $$file;         \
	}
	@${ECHO} -n " .c files,"
	@for file in `${FIND} ${WRKSRC} -name "*.c" -print`; {                \
		${MV} $$file $$file.old;                                      \
		${SED} -e 's/roken.h/arla-roken.h/g' $$file.old > $$file;     \
	}
	@${ECHO} -n " .h files,"
	@for file in `${FIND} ${WRKSRC} -name "*.h" -print`; {                \
		${MV} $$file $$file.old;                                      \
		${SED} -e 's/roken.h/arla-roken.h/g' $$file.old > $$file;     \
	}
	@${ECHO} -n " .y files,"
	@for file in `${FIND} ${WRKSRC} -name "*.y" -print`; {                \
		${MV} $$file $$file.old;                                      \
		${SED} -e 's/roken.h/arla-roken.h/g' $$file.old > $$file;     \
	}
	@${ECHO} -n " .l files"
	@for file in `${FIND} ${WRKSRC} -name "*.l" -print`; {                \
		${MV} $$file $$file.old;                                      \
		${SED} -e 's/roken.h/arla-roken.h/g' $$file.old > $$file;     \
	}
	@${ECHO} "."
	@${MV} ${WRKSRC}/lib/roken/roken.h ${WRKSRC}/lib/roken/arla-roken.h
	@${MV} ${WRKSRC}/lib/roken ${WRKSRC}/lib/arla-roken

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
		${MKDIR} ${CACHEDIR};                                         \
		${CHMOD} 700 ${CACHEDIR};                                     \
		${CHOWN} root ${CACHEDIR};                                    \
	fi
	@if [ -e /sbin/mount_xfs ]; then                                      \
		${ECHO} "/sbin/mount_xfs already exists";                     \
	else                                                                  \
		${ECHO} "Creating /sbin/mount_xfs";                           \
		${LN} -s ${PREFIX}/bin/mount_xfs /sbin/mount_xfs;             \
	fi
	@-${MKDIR} ${PREFIX}/share/examples/arla
	@${SED} -e 's|@PREFIX@|${PREFIX}|g'                                   \
		< ${FILESDIR}/lkm.conf                                        \
		> ${PREFIX}/share/examples/arla/lkm.conf
	@${INSTALL} -c -o root -g wheel -m 444                                \
		${FILESDIR}/services ${PREFIX}/share/examples/arla
	@${INSTALL} -c -o root -g wheel -m 444                                \
		 ${FILESDIR}/fstab ${PREFIX}/share/examples/arla
	@${SED} -e 's|@PREFIX@|${PREFIX}|' ${FILESDIR}/arlad.sh               \
		> ${PREFIX}/etc/rc.d/arlad
	@${ECHO} " "

.include "../../mk/bsd.pkg.mk"
