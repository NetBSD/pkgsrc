# $NetBSD: Makefile,v 1.17 2001/09/27 23:18:37 jlam Exp $

DISTNAME=		cyrus-sasl-1.5.24
PKGNAME=		${DISTNAME}nb3
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
			ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/OLD-VERSIONS/sasl/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://asg2.web.cmu.edu/sasl/
COMMENT=		Simple Authentication and Security Layer

BUILD_DEPENDS+=		automake>=1.4:../../devel/automake

GNU_CONFIGURE=		# defined
USE_SSL=		# defined
USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/config/ltconfig

.include "../../mk/bsd.prefs.mk"

# CYRUS_USER		username of the Cyrus administrator
# CYRUS_GROUP		group of the Cyrus administrator
#
CYRUS_USER?=		cyrus
CYRUS_GROUP?=		mail

BUILD_DEFS+=		CYRUS_USER CYRUS_GROUP

PLIST_SRC=		${PKGDIR}/PLIST.common

CONFIGURE_ARGS+=	--with-pwcheck=/var/pwcheck
CONFIGURE_ARGS+=	--with-dblib=ndbm
CONFIGURE_ARGS+=	--with-dbpath=/etc/sasldb
CONFIGURE_ARGS+=	--with-plugindir=${PREFIX}/lib/sasl
CONFIGURE_ARGS+=	--with-rc4=${SSLBASE}

.if defined(USE_PAM)
CONFIGURE_ARGS+=	--with-pam=${PREFIX}
DEPENDS+=		PAM-[0-9]*:../../security/PAM
.endif

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

PLIST_SRC+=		${PKGDIR}/PLIST.plugins

.if ${OPSYS} == "NetBSD"
.if exists(/usr/sbin/user)
ADDUSER=		/usr/sbin/useradd
ADDGROUP=		/usr/sbin/groupadd
.else
DEPENDS+=		user>=20000313:../../sysutils/user
ADDUSER=		${LOCALBASE}/sbin/useradd
ADDGROUP=		${LOCALBASE}/sbin/groupadd
.endif
.elif ${OPSYS} == "SunOS"
ADDUSER=		useradd
ADDGROUP=		groupadd
.endif

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

HTMLDIR=		${PREFIX}/share/doc/html/cyrus-sasl

post-extract:
	cd ${WRKSRC}; ${RM} -f include/md5.h
	${CP} ${FILESDIR}/sasl-config.in ${WRKSRC}/plugins

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoheader && ${LOCALBASE}/bin/autoconf && ${LOCALBASE}/bin/automake --gnu

post-build:
	${SED}	-e "s,@PREFIX@,${PREFIX},g" \
		< ${FILESDIR}/sasl_pwcheck.sh > ${WRKDIR}/sasl_pwcheck.sh

pre-install:
	${SED}	-e "s,@CYRUS_USER@,${CYRUS_USER},g" \
		-e "s,@CYRUS_GROUP@,${CYRUS_GROUP},g" \
		-e "s,@CAT@,${CAT},g" \
		-e "s,@RM@,${RM},g" \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s,@CYRUS_USER@,${CYRUS_USER},g" \
		-e "s,@CYRUS_GROUP@,${CYRUS_GROUP},g" \
		-e "s,@ADDUSER@,${ADDUSER},g" \
		-e "s,@ADDGROUP@,${ADDGROUP},g" \
		-e "s,@CHGRP@,${CHGRP},g" \
		-e "s,@CHMOD@,${CHMOD},g" \
		-e "s,@CHOWN@,${CHOWN},g" \
		-e "s,@ID@,${ID},g" \
		-e "s,@MKDIR@,${MKDIR},g" \
		-e "s,@RM@,${RM},g" \
		-e "s,@TOUCH@,${TOUCH},g" \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/sasl_pwcheck.sh \
		${PREFIX}/etc/rc.d/sasl_pwcheck
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.txt ${HTMLDIR}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
