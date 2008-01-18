# $NetBSD: Makefile,v 1.42 2008/01/18 05:09:39 tnn Exp $

# NOTE:  This package is modeled on ../openssh, but does not share
# files with it as that package may update faster than the gssapi
# patches do.

DISTNAME=		openssh-3.6.1p2
PKGNAME=		openssh+gssapi-3.6.1.2.20030430
PKGREVISION=		8
SVR4_PKGNAME=		osshgss
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.stealth.net/pub/mirrors/ftp.openssh.com/pub/OpenBSD/OpenSSH/portable/ \
			http://public.planetmirror.com.au/pub/OpenBSD/OpenSSH/portable/ \
			ftp://ftp.openssh.com/pub/OpenBSD/OpenSSH/portable/ \
			ftp://gd.tuwien.ac.at/opsys/OpenBSD/OpenSSH/portable/ \
			ftp://ftp.openssh.com/pub/OpenBSD/OpenSSH/portable/old/
PATCH_SITES=	http://www.sxw.org.uk/computing/patches/
PATCHFILES=	openssh-3.6.1p2-gssapi-20030430.diff
PATCH_DIST_STRIP=	-p1

# Don't delete the last entry -- it's there if the pkgsrc version is not
# up-to-date and the mirrors already removed the old distfile.

MAINTAINER=		jwise@NetBSD.org
HOMEPAGE=		http://www.openssh.com/
COMMENT=		Open Source Secure shell client and server with enhanced GSSAPI support

CONFLICTS=		sftp-[0-9]*
CONFLICTS+=		ssh-[0-9]* ssh6-[0-9]* ssh2-[0-9]*
CONFLICTS+=		openssh-[0-9]*
CONFLICTS+=		lsh>2.0

CRYPTO=			yes
KERBEROS=		yes

# retain the following line, for IPv6-ready pkgsrc webpage
BUILD_DEFS+=		IPV6_READY
#BUILD_DEFS+=		KERBEROS

.include "../../mk/bsd.prefs.mk"

INSTALL_TARGET=		install-nokeys
PLIST_SRC=		# empty
MESSAGE_SRC=		${.CURDIR}/MESSAGE

PKG_GROUPS_VARS+=	OPENSSH_GROUP
PKG_USERS_VARS+=	OPENSSH_USER

PKG_GROUPS=		${OPENSSH_GROUP}
PKG_USERS=		${OPENSSH_USER}:${OPENSSH_GROUP}

PKG_GECOS.${OPENSSH_USER}=	sshd privsep pseudo-user
PKG_HOME.${OPENSSH_USER}=	${OPENSSH_CHROOT}

SSH_PID_DIR=		/var/run	# default directory for PID files

PKG_SYSCONFSUBDIR=	ssh

USE_TOOLS+=		autoconf perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-pid-dir=${SSH_PID_DIR:Q}
CONFIGURE_ARGS+=	--with-ssl-dir=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-tcp-wrappers=${BUILDLINK_PREFIX.tcp_wrappers}
CONFIGURE_ARGS+=	--with-privsep-path=${OPENSSH_CHROOT:Q}
CONFIGURE_ARGS+=	--with-privsep-user=${OPENSSH_USER:Q}
CONFIGURE_ARGS+=	--with-kerberos5=/usr

CPPFLAGS+=		-I/usr/include/krb5

# XXX: PAM authentication causes memory faults, and I haven't tracked down
# XXX: why yet.  For the moment, disable PAM authentication.
#
#PKG_OPTIONS_VAR=	PKG_OPTIONS.openssh+gssapi
#PKG_SUPPORTED_OPTIONS=	pam
#.include "../../mk/bsd.options.mk"
#
#.if !empty(PKG_OPTIONS:Mpam)
#.  include "../../mk/pam.buildlink3.mk"
#CONFIGURE_ARGS+=	--with-pam
#PLIST_SRC+=		${.CURDIR}/PLIST.pam
#MESSAGE_SRC+=		${.CURDIR}/MESSAGE.pam
#.endif

.if (${OPSYS} == "Darwin") || (${OPSYS} == "SunOS")
.  include "../../security/skey/buildlink3.mk"
CONFIGURE_ARGS+=	--with-skey=${BUILDLINK_PREFIX.skey}
.elif ${OPSYS} == "NetBSD"
# XXX: NetBSD has 4 args (4: sslen) to skeychallenge instead of 3
#CONFIGURE_ARGS+=	--with-skey=/usr
CONFIGURE_ARGS+=	--without-skey
.else
CONFIGURE_ARGS+=	--without-skey
.endif

.if defined(KERBEROS)
.include "../../security/kth-krb4/buildlink3.mk"
PKG_USE_KERBEROS=		yes
CONFIGURE_ARGS+=	--with-kerberos4=${BUILDLINK_PREFIX.kth-krb4}
CPPFLAGS+=		-I${BUILDLINK_PREFIX.kth-krb4}/include/kerberosIV
LDFLAGS+=		-L${BUILDLINK_PREFIX.kth-krb4}/lib
LDFLAGS+=		-Wl,-R${BUILDLINK_PREFIX.kth-krb4}/lib
LDFLAGS+=		-lkrb -lcom_err -lroken -ldes -lcrypto
.endif

CONFIGURE_ENV+=		LD=${CC:Q}

# The ssh-askpass program is in ${X11BASE}/bin or ${X11PREFIX}/bin depending
# on if it's part of the X11 distribution, or if it's installed from pkgsrc
# (security/ssh-askpass).
#
.if exists(${X11BASE}/bin/ssh-askpass)
ASKPASS_PROGRAM=	${X11BASE}/bin/ssh-askpass
.else
ASKPASS_PROGRAM=	${X11PREFIX}/bin/ssh-askpass
.endif
CONFIGURE_ENV+=		ASKPASS_PROGRAM=${ASKPASS_PROGRAM:Q}
MAKE_ENV+=		ASKPASS_PROGRAM=${ASKPASS_PROGRAM:Q}

CONFS=			ssh_config sshd_config moduli

.if exists(/dev/urandom)
MESSAGE_SRC+=		${.CURDIR}/MESSAGE.urandom
.else
CONFIGURE_ARGS+=	--without-random
CONFS+=			ssh_prng_cmds
PLIST_SRC+=		${.CURDIR}/PLIST.prng
.endif

EGDIR=			${PREFIX}/share/examples/openssh
CONF_FILES=		# empty
.for FILE in ${CONFS}
CONF_FILES+=		${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}
.endfor
OWN_DIRS=		${OPENSSH_CHROOT}
RCD_SCRIPTS=		sshd

PLIST_SRC+=		${.CURDIR}/PLIST
FILES_SUBST+=		SSH_PID_DIR=${SSH_PID_DIR:Q}
MESSAGE_SUBST+=		EGDIR=${EGDIR}
MESSAGE_SUBST+=		OPENSSH_USER=${OPENSSH_USER}
MESSAGE_SUBST+=		OPENSSH_GROUP=${OPENSSH_GROUP}

pre-configure:
	cd ${WRKSRC} && autoreconf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}; for file in ${CONFS}; do				\
		${INSTALL_DATA} $${file}.out ${EGDIR}/$${file};		\
	done
#.if !empty(PKT_OPTIONS:Mpam)
#	${INSTALL_DATA} ${WRKSRC}/contrib/sshd.pam.freebsd ${EGDIR}/sshd.pam
#.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
