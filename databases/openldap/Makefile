# $NetBSD: Makefile,v 1.13 1999/09/17 06:46:31 simonb Exp $
#

DISTNAME=	openldap-1.2.7
PKGNAME=	openldap-1.2.7p1
WRKSRC=		${WRKDIR}/ldap
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.openldap.org/pub/OpenLDAP/openldap-release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.OpenLDAP.org/

# for the moment without threads and thus without slurpd and ldapd
#DEPENDS+=	../../devel/mit-pthreads

CONFLICTS+=	ldapsdk*

USE_LIBTOOL=	yes

# unfortunately, --enable-phonetic cannot be disabled by runtime configuration
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-dns --enable-cldap \
		--enable-wrappers --enable-passwd --enable-shell

post-configure:
	${ECHO} "SLAPD_LIBS = " >> ${WRKSRC}/servers/slapd/tools/Makefile

.include "../../mk/bsd.prefs.mk"

.if defined(KERBEROS) && ${KERBEROS} == 4
USE_KERBEROS=	yes
CONFIGURE_ARGS+=--with-kerberos
.else
CONFIGURE_ARGS+=--without-kerberos
.endif

.include "../../mk/bsd.pkg.mk"
