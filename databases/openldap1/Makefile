# $NetBSD: Makefile,v 1.3 2002/06/15 21:20:00 cjep Exp $
#

DISTNAME=	openldap-1.2.13
SVR4_PKGNAME=	olda1
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.openldap.org/pub/OpenLDAP/openldap-release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kleink@netbsd.org
HOMEPAGE=	http://www.OpenLDAP.org/
COMMENT=	Lightweight directory access protocol server and client package

# for the moment without threads and thus without slurpd and ldapd
#DEPENDS+=	../../devel/mit-pthreads

CONFLICTS+=	ldapsdk-[0-9]*

USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/build/ltconfig

# unfortunately, --enable-phonetic cannot be disabled by runtime configuration
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-dns
CONFIGURE_ARGS+=	--enable-cldap
CONFIGURE_ARGS+=	--enable-passwd
CONFIGURE_ARGS+=	--enable-shell

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--enable-wrappers
.endif

.if ${OPSYS} == "SunOS"
.include "../../databases/db/buildlink.mk"
CPPFLAGS+=	-I${BUILDLINK_DIR}/include/db2
LIBS=		-ldb2 -lpthread -lrt
.endif

PLIST_SRC=	${PKGDIR}/PLIST.common
PLIST_SRC+=	${PKGDIR}/PLIST.${LOWER_OPSYS}

post-configure:
	${ECHO} "SLAPD_LIBS = " >> ${WRKSRC}/servers/slapd/tools/Makefile

.if defined(KERBEROS)
PKG_USE_KERBEROS=	yes
CONFIGURE_ARGS+=--with-kerberos
.else
CONFIGURE_ARGS+=--without-kerberos
.endif

.include "../../mk/bsd.pkg.mk"
