# $NetBSD: Makefile,v 1.135 2004/04/28 05:26:39 jlam Exp $

DISTNAME=		openssh-3.8p1
PKGNAME=		openssh-3.8.1
PKGREVISION=		3
SVR4_PKGNAME=		ossh
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.openssh.com/pub/OpenBSD/OpenSSH/portable/ \
			ftp://ftp7.usa.openbsd.org/pub/os/OpenBSD/OpenSSH/portable/ \
			ftp://ftp.stealth.net/pub/mirrors/ftp.openssh.com/pub/OpenBSD/OpenSSH/portable/ \
			http://public.planetmirror.com.au/pub/OpenBSD/OpenSSH/portable/ \
			ftp://gd.tuwien.ac.at/opsys/OpenBSD/OpenSSH/portable/ \
			ftp://ftp.openssh.com/pub/OpenBSD/OpenSSH/portable/old/
# Don't delete the last entry -- it's there if the pkgsrc version is not
# up-to-date and the mirrors already removed the old distfile.

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.openssh.com/
COMMENT=		Open Source Secure shell client and server (remote login program)

CONFLICTS=		sftp-[0-9]*
CONFLICTS+=		ssh-[0-9]* ssh6-[0-9]* ssh2-[0-9]*
CONFLICTS+=		openssh+gssapi-[0-9]*

USE_PERL5=		build

CRYPTO=			yes

# retain the following line, for IPv6-ready pkgsrc webpage
BUILD_DEFS+=		USE_INET6
BUILD_DEFS+=		KERBEROS

.include "../../mk/bsd.prefs.mk"

INSTALL_TARGET=		install-nokeys
PLIST_SRC=		# empty
MESSAGE_SRC=		${.CURDIR}/MESSAGE

PKG_USERS=		${OPENSSH_USER}:${OPENSSH_GROUP}:${OPENSSH_UID}:sshd\\ privsep:${OPENSSH_CHROOT}:${NOLOGIN}
PKG_GROUPS=             ${OPENSSH_GROUP}:${OPENSSH_GID}

SSH_PID_DIR=		/var/run	# default directory for PID files

PKG_SYSCONFSUBDIR=	ssh
MANDIR=			man

PLIST_SUBST+=		MANDIR=${MANDIR}

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-mantype=man
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${MANDIR}
CONFIGURE_ARGS+=	--with-pid-dir=${SSH_PID_DIR}
CONFIGURE_ARGS+=	--with-ssl-dir=${SSLBASE}
CONFIGURE_ARGS+=	--with-tcp-wrappers=${BUILDLINK_PREFIX.tcp_wrappers}
CONFIGURE_ARGS+=	--with-privsep-path=${OPENSSH_CHROOT}
CONFIGURE_ARGS+=	--with-privsep-user=${OPENSSH_USER}

# XXX: PAM authentication causes memory faults, and I haven't tracked down
# XXX: why yet.  For the moment, disable PAM authentication.
#
#.if defined(USE_PAM)
#.include "../../security/PAM/buildlink3.mk"
#CONFIGURE_ARGS+=	--with-pam
#PLIST_SRC+=		${.CURDIR}/PLIST.pam
#MESSAGE_SRC+=		${.CURDIR}/MESSAGE.pam
#.endif

# the openssh configure script finds and uses ${LD} if defined and
# defaults to ${CC} if not. we override LD here, since running the
# linker directly results in undefined symbols for obvious reasons.
#
CONFIGURE_ENV+=		LD=${CC:Q}

# Enable S/Key support on NetBSD, Darwin, and Solaris.
.if (${OPSYS} == "NetBSD") || (${OPSYS} == "Darwin") || (${OPSYS} == "SunOS")
.  include "../../security/skey/buildlink3.mk"
CONFIGURE_ARGS+=	--with-skey=${BUILDLINK_PREFIX.skey}
#
# NetBSD's skeychallenge() takes 4 args (int: sslen) instead of 3.
#
.  if ${OPSYS} == "NetBSD"
CPPFLAGS+=		-DSKEYCHALLENGE=SKEYCHALLENGE4
.  endif
.else
CONFIGURE_ARGS+=	--without-skey
.endif

.if defined(KERBEROS)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-kerberos5=${KRB5BASE}
.endif

.if (${OPSYS} == "NetBSD") && exists(/usr/include/utmpx.h)
# if we have utmpx et al do not try to use login()
CONFIGURE_ARGS+=	--disable-libutil
.endif
.if (${OPSYS} == "SunOS") && (${OS_VERSION} == "5.8" || ${OS_VERSION} == "5.9")
CONFIGURE_ARGS+=	--disable-utmp --disable-wtmp
.endif

# The ssh-askpass program is in ${X11BASE}/bin or ${X11PREFIX}/bin depending
# on if it's part of the X11 distribution, or if it's installed from pkgsrc
# (security/ssh-askpass).
#
.if exists(${X11BASE}/bin/ssh-askpass)
ASKPASS_PROGRAM=	${X11BASE}/bin/ssh-askpass
.else
ASKPASS_PROGRAM=	${X11PREFIX}/bin/ssh-askpass
.endif
CONFIGURE_ENV+=		ASKPASS_PROGRAM=${ASKPASS_PROGRAM}
MAKE_ENV+=		ASKPASS_PROGRAM=${ASKPASS_PROGRAM}

CONFS=			ssh_config sshd_config
SUPPS=			moduli

.if exists(/dev/urandom)
MESSAGE_SRC+=		${.CURDIR}/MESSAGE.urandom
.else
CONFIGURE_ARGS+=	--without-random
CONFS+=			ssh_prng_cmds
PLIST_SRC+=		${.CURDIR}/PLIST.prng
.endif

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		# empty
.for FILE in ${CONFS}
CONF_FILES+=		${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}
.endfor
SUPPORT_FILES=		# empty
.for FILE in ${SUPPS}
SUPPORT_FILES+=		${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}
.endfor
OWN_DIRS=		${OPENSSH_CHROOT}
RCD_SCRIPTS=		sshd

PLIST_SRC+=		${.CURDIR}/PLIST
FILES_SUBST+=		SSH_PID_DIR=${SSH_PID_DIR}
MESSAGE_SUBST+=		EGDIR=${EGDIR}
MESSAGE_SUBST+=		OPENSSH_USER=${OPENSSH_USER}
MESSAGE_SUBST+=		OPENSSH_GROUP=${OPENSSH_GROUP}

INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}; for file in ${CONFS} ${SUPPS}; do			\
		${INSTALL_DATA} $${file}.out ${EGDIR}/$${file};		\
	done
#.if defined(USE_PAM)
#	${INSTALL_DATA} ${WRKSRC}/contrib/sshd.pam.freebsd ${EGDIR}/sshd.pam
#.endif

.include "../../mk/bsd.pkg.mk"
