# $NetBSD: Makefile,v 1.10 1999/08/18 09:28:01 agc Exp $
#

DISTNAME=	openldap-1.2.1
PKGNAME=	openldap-1.2.1p1
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

BUILD_DEFS+=	USE_KERBEROS4

.include "../../mk/bsd.prefs.mk"

.if !defined(USE_KERBEROS4)
CONFIGURE_ARGS+=--without-kerberos
.else
RESTRICTED=	uses Kerberos encryption code
.endif

.include "../../mk/bsd.pkg.mk"
