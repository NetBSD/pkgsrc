# $NetBSD: Makefile,v 1.61 2014/02/12 23:18:33 tron Exp $
#

DISTNAME=		krb4-1.2.2
PKGNAME=		kth-krb4-1.2.2
PKGREVISION=		8
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.pdc.kth.se/pub/krb/src/

MAINTAINER=		wennmach@NetBSD.org
HOMEPAGE=		http://www.pdc.kth.se/kth-krb/
COMMENT=		Kerberos IV distribution from KTH

CONFLICTS+=		arla-[0-9]*
CONFLICTS+=		libdes-[0-9]*
CONFLICTS+=		man-pages-[0-9]*
CONFLICTS+=		heimdal-[0-9]*

CRYPTO=			yes

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		yacc
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/kerberosIV

.include "../../mk/bsd.prefs.mk"
KERBEROS_PREFIX_CMDS?=	no
KRB4_PREFIX_CMDS?=	${KERBEROS_PREFIX_CMDS}
BUILD_DEFS+=		KRB4_PREFIX_CMDS
.if !empty(KRB4_PREFIX_CMDS:M[yY][eE][sS])
KTH_KRB4_TRANSFORM=	s/^ftp/k4&/;\
			s/^rcp/k4&/;\
			s/^rlogin/k4&/;\
			s/^rsh/k4&/;\
			s/^su/k4&/;\
			s/^telnet/k4&/
PLIST_SUBST+=		KRB4_PREFIX=k4
.else
KTH_KRB4_TRANSFORM=	s/^ftp$$/k4&/	# always k4ftp
PLIST_SUBST+=		KRB4_PREFIX=
.endif
CONFIGURE_ARGS+=	--program-transform=${KTH_KRB4_TRANSFORM:Q}

INFO_FILES=		yes
EXAMPLEDIR=		${PREFIX}/share/examples/kth-krb4

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKSRC}/lib/kafs/kafs.h
SUBST_SED.paths+=	-e 's|/usr/arla/etc/|${PKG_SYSCONFDIR}|g'
SUBST_STAGE.paths=	post-patch

# On some systems, kth-krb4's libroken installs a glob.h to compensate
# for the system not having one.  Please turn PLIST support for this
# on narrowly.
INSTALLS_GLOB=	no
.if ${INSTALLS_GLOB} == yes
PLIST.glob=			yes
.endif

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-readline=yes \
	--with-readline-lib=${BUILDLINK_PREFIX.editlinereadline}/lib \
	--with-readline-include=${BUILDLINK_PREFIX.editlinereadline}/include/readline \
	ac_cv_funclib_bswap16=yes \
	ac_cv_funclib_bswap32=yes

.include "../../mk/readline.buildlink3.mk"
.endif

PLIST_VARS+=	glob wantdes

.if ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD"
CPPFLAGS+=	-DOPENSSL_DES_LIBDES_COMPATIBILITY
.if ${MACHINE_ARCH} == "x86_64" || ${MACHINE_ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif
.else
PLIST.wantdes=	yes
.endif

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/krb.conf ${DESTDIR}${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/krb.realms ${DESTDIR}${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/inetd.conf.changes ${DESTDIR}${EXAMPLEDIR}
	${INSTALL_DATA} ${FILESDIR}/services-1.4.2.diff ${DESTDIR}${EXAMPLEDIR}
	${INSTALL_DATA} ${FILESDIR}/services-1.5.diff ${DESTDIR}${EXAMPLEDIR}

SPECIAL_PERMS+=	bin/${KRB4_PREFIX}rsh ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	bin/${KRB4_PREFIX}rcp ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	bin/${KRB4_PREFIX}rlogin ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	bin/${KRB4_PREFIX}su ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	bin/otp ${SETUID_ROOT_PERMS}

.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
