# $NetBSD: Makefile,v 1.20 2001/11/25 18:59:47 jlam Exp $

DISTNAME=		cyrus-sasl-1.5.24
PKGNAME=		${DISTNAME}nb3
SVR4_PKGNAME=		csasl
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
			ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/OLD-VERSIONS/sasl/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://asg2.web.cmu.edu/sasl/
COMMENT=		Simple Authentication and Security Layer

BUILD_DEPENDS+=		automake>=1.4:../../devel/automake

AUTOMAKE_OVERRIDE=	YES
USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/config/ltconfig

.include "../../mk/bsd.prefs.mk"

# CYRUS_USER		username of the Cyrus administrator
# CYRUS_GROUP		group of the Cyrus administrator
#
CYRUS_USER?=		cyrus
CYRUS_GROUP?=		mail

HTMLDIR=		${PREFIX}/share/doc/html/cyrus-sasl
PWCHECKDIR=		/var/pwcheck
FILES_SUBST+=		PWCHECKDIR=${PWCHECKDIR}

BUILD_DEFS+=		CYRUS_USER CYRUS_GROUP

PLIST_SRC=		${PKGDIR}/PLIST.common

CONFIGURE_ARGS+=	--with-pwcheck=${PWCHECKDIR}
CONFIGURE_ARGS+=	--with-dblib=ndbm
CONFIGURE_ARGS+=	--with-dbpath=${PKG_SYSCONFDIR}/sasldb
CONFIGURE_ARGS+=	--with-plugindir=${PREFIX}/lib/sasl
CONFIGURE_ARGS+=	--with-rc4=${BUILDLINK_DIR}

# Authentication mechanisms
CONFIGURE_ARGS+=	--enable-anon		# ANONYMOUS
CONFIGURE_ARGS+=	--enable-cram		# CRAM-MD5
CONFIGURE_ARGS+=	--enable-digest		# DIGEST-MD5
CONFIGURE_ARGS+=	--disable-login		# --- no LOGIN
CONFIGURE_ARGS+=	--enable-plain		# PLAIN
CONFIGURE_ARGS+=	--disable-scram		# --- no SCRAM-MD5
CONFIGURE_ARGS+=	--disable-sia		# --- no SIA
CONFIGURE_ARGS+=	--disable-srp		# --- no SRP
CONFIGURE_ARGS+=	--disable-x509		# --- no X.509

.if defined(KERBEROS)
.undef USE_BUILDLINK_ONLY
.if ${OPSYS} == "NetBSD"
USE_KERBEROS=		# defined
CONFIGURE_ARGS+=	--enable-krb4=${PREFIX} --enable-gssapi=/usr # KERBEROS_V4
DEPENDS+=		kth-krb4-[0-9]*:../../security/kth-krb4
PLIST_SRC+=		${PKGDIR}/PLIST.krb4 ${PKGDIR}/PLIST.krb5
.elif ${OPSYS} == "SunOS"
USE_KERBEROS=		# defined
CONFIGURE_ARGS+=	--enable-gssapi=/usr	# GSSAPI
PLIST_SRC+=		${PKGDIR}/PLIST.krb5
.else
CONFIGURE_ARGS+=	--disable-krb4 --disable-gssapi # --- no KERBEROS_V4
.endif
.endif

PLIST_SRC+=		${PKGDIR}/PLIST.plugins

.if defined(USE_PAM)
CONFIGURE_ARGS+=	--with-pam=${PREFIX}
.include "../../security/PAM/buildlink.mk"
.endif

PKG_USER=		${CYRUS_USER}
PKG_USER_SHELL=		${SH}
PKG_GROUP=		${CYRUS_GROUP}
RCD_SCRIPTS=		sasl_pwcheck
OWN_DIRS_PERMS=		${PWCHECKDIR} ${PKG_USER} ${ROOT_GROUP} 0700

DEINSTALL_EXTRA_TMPL=	${PKGDIR}/DEINSTALL

post-extract:
	cd ${WRKSRC}; ${RM} -f include/md5.h
	${CP} ${FILESDIR}/sasl-config.in ${WRKSRC}/plugins

pre-configure:
	cd ${WRKSRC};							\
	${LOCALBASE}/bin/autoheader;					\
	${LOCALBASE}/bin/automake --gnu;				\
	${LOCALBASE}/bin/autoconf

pre-install:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/sasl_pwcheck.sh		\
		> ${WRKDIR}/sasl_pwcheck.sh
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/sasl_pwcheck.sh \
		${PREFIX}/etc/rc.d/sasl_pwcheck
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.txt ${HTMLDIR}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
