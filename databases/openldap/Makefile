# $NetBSD: Makefile,v 1.22 2001/05/14 16:15:52 kleink Exp $
#

DISTNAME=	openldap-1.2.12
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.openldap.org/pub/OpenLDAP/openldap-release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.OpenLDAP.org/
COMMENT=	Lightweight directory access protocol server and client package

# for the moment without threads and thus without slurpd and ldapd
#DEPENDS+=	../../devel/mit-pthreads

CONFLICTS+=	ldapsdk*

USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/build/ltconfig

.include "../../mk/bsd.prefs.mk"

# unfortunately, --enable-phonetic cannot be disabled by runtime configuration
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-dns --enable-cldap --enable-passwd --enable-shell
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+= --enable-wrappers
.endif

.if ${OPSYS} == "SunOS"
DEPENDS+=	db-2.7.7:../../databases/db
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include/db2"
CONFIGURE_ENV+=	LIBS="-ldb2 -lpthread -lrt"
.endif

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

post-build:
	${CAT} ${PKGDIR}/PLIST.common ${PKGDIR}/PLIST.${LOWER_OPSYS} > ${PLIST_SRC}

post-configure:
	${ECHO} "SLAPD_LIBS = " >> ${WRKSRC}/servers/slapd/tools/Makefile

.if defined(KERBEROS)
USE_KERBEROS=	yes
CONFIGURE_ARGS+=--with-kerberos
.else
CONFIGURE_ARGS+=--without-kerberos
.endif

.include "../../mk/bsd.pkg.mk"
