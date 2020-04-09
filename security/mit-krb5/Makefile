# $NetBSD: Makefile,v 1.106 2020/04/09 10:57:04 adam Exp $

DISTNAME=	krb5-1.18
PKGNAME=	mit-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://web.mit.edu/kerberos/dist/krb5/${PKGVERSION_NOREV}/

MAINTAINER=	tez@NetBSD.org
HOMEPAGE=	https://web.mit.edu/kerberos/
COMMENT=	MIT Kerberos 5 authentication system

MAKE_JOBS_SAFE=	no

WRKSRC=		${WRKDIR}/${DISTNAME}/src

BUILD_TARGET=	generate-files-mac all

.include "../../mk/bsd.prefs.mk"

CONFLICTS+=	heimdal-[0-9]*
CONFLICTS+=	kth-krb4-[0-9]*

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf gzip m4 msgfmt perl
.if ${OPSYS} == "SunOS"
USE_TOOLS+=		bison
.else
USE_TOOLS+=		yacc
.endif

# The actual KDC databases are stored in ${MIT_KRB5_STATEDIR}/krb5kdc.
MIT_KRB5_STATEDIR?=	${VARBASE}
FILES_SUBST+=		MIT_KRB5_STATEDIR=${MIT_KRB5_STATEDIR}

BUILD_DEFS+=		VARBASE

CONFIGURE_ARGS+=	--localstatedir=${MIT_KRB5_STATEDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-aesni
CONFIGURE_ARGS+=	--disable-kdc-lookaside-cache
CONFIGURE_ARGS+=	--disable-thread-support
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-dns-for-realm
CONFIGURE_ARGS+=	--enable-pkgsrc-libtool
CONFIGURE_ARGS+=	--without-system-verto
CONFIGURE_ARGS+=	--without-tcl
CONFIGURE_ENV+=		BUILDLINK_PREFIX_OPENSSL=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ENV+=		DEFKTNAME=FILE:${PKG_SYSCONFDIR}/krb5.keytab
MAKE_ENV+=		ROOT_USER=${ROOT_USER}
LIBS.SunOS=		-lrt

OWN_DIRS_PERMS=		${MIT_KRB5_STATEDIR}/krb5kdc			\
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700
RCD_SCRIPTS=		kadmind kdc

INSTALLATION_DIRS=	bin include/gssapi include/gssrpc ${PKGINFODIR}	\
			${PKGMANDIR}/man1 ${PKGMANDIR}/man5		\
			${PKGMANDIR}/man7 ${PKGMANDIR}/man8		\
			sbin share/examples/krb5 share/et		\
			share/examples/rc.d share/gnats			\
			lib/krb5/plugins/kdb lib/krb5/plugins/preauth	\
			lib/krb5/plugins/tls include/krb5 include/kadm5 \
			lib/pkgconfig

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && autoconf -I ${WRKSRC} -f

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
