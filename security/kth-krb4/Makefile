# $NetBSD: Makefile,v 1.36 2004/10/03 00:18:09 tv Exp $
#

DISTNAME=		krb4-1.2.1
PKGNAME=		kth-krb4-1.2.1
PKGREVISION=		5
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.pdc.kth.se/pub/krb/src/

MAINTAINER=		wennmach@NetBSD.org
HOMEPAGE=		http://www.pdc.kth.se/kth-krb/
COMMENT=		Kerberos IV distribution from KTH

CONFLICTS+=		zephyr-[0-9]*
CONFLICTS+=		libdes-[0-9]*

CRYPTO=			yes

USE_BUILDLINK3=		yes
USE_X11=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
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
CONFIGURE_ARGS+=	--program-transform="${KTH_KRB4_TRANSFORM}"

INFO_FILES=		kth-krb.info

EXAMPLEDIR=		${PREFIX}/share/examples/kth-krb4

# this hangs while compiling one of the files, at least with the
# toolchain as of 1.5ZC (20020329)
#.if ${MACHINE_ARCH} == "sparc64"
#BROKEN=			toolchain problems on sparc64 (1.5ZC, 20020329)
#.endif

post-patch:
	@for file in ${WRKSRC}/lib/kafs/kafs.h; do			\
		${SED}	-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g'	\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/krb.conf ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/krb.realms ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/inetd.conf.changes ${EXAMPLEDIR}
	${INSTALL_DATA} ${FILESDIR}/services-1.4.2.diff ${EXAMPLEDIR}
	${INSTALL_DATA} ${FILESDIR}/services-1.5.diff ${EXAMPLEDIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
