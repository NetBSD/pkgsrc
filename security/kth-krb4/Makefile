# $NetBSD: Makefile,v 1.48 2008/01/18 05:09:38 tnn Exp $
#

DISTNAME=		krb4-1.2.2
PKGNAME=		kth-krb4-1.2.2
#PKGREVISION=		1
PKGREVISION=		1
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.pdc.kth.se/pub/krb/src/

MAINTAINER=		wennmach@NetBSD.org
HOMEPAGE=		http://www.pdc.kth.se/kth-krb/
COMMENT=		Kerberos IV distribution from KTH

CONFLICTS+=		arla-[0-9]*
CONFLICTS+=		libdes-[0-9]*

CRYPTO=			yes

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
CONFIGURE_ARGS+=	--program-transform=${KTH_KRB4_TRANSFORM:Q}

INFO_FILES=		yes
EXAMPLEDIR=		${PREFIX}/share/examples/kth-krb4

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKSRC}/lib/kafs/kafs.h
SUBST_SED.paths+=	-e 's|/usr/arla/etc/|${PKG_SYSCONFDIR}|g'
SUBST_STAGE.paths=	post-patch

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/krb.conf ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/krb.realms ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/inetd.conf.changes ${EXAMPLEDIR}
	${INSTALL_DATA} ${FILESDIR}/services-1.4.2.diff ${EXAMPLEDIR}
	${INSTALL_DATA} ${FILESDIR}/services-1.5.diff ${EXAMPLEDIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
