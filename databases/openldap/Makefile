# $NetBSD: Makefile,v 1.16 2000/06/15 12:54:10 kleink Exp $
#

DISTNAME=	openldap-1.2.11
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.openldap.org/pub/OpenLDAP/openldap-release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.OpenLDAP.org/

# for the moment without threads and thus without slurpd and ldapd
#DEPENDS+=	../../devel/mit-pthreads

CONFLICTS+=	ldapsdk*

USE_PKGLIBTOOL=	yes

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

post-configure:
	${ECHO} "SLAPD_LIBS = " >> ${WRKSRC}/servers/slapd/tools/Makefile

.if defined(KERBEROS) && ${KERBEROS} == 4
USE_KERBEROS=	yes
CONFIGURE_ARGS+=--with-kerberos
.else
CONFIGURE_ARGS+=--without-kerberos
.endif

.include "../../mk/bsd.pkg.mk"
