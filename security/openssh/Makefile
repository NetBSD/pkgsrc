# $NetBSD: Makefile,v 1.159 2005/10/07 17:42:35 reed Exp $

DISTNAME=		openssh-4.2p1
PKGNAME=		openssh-4.2.1
PKGREVISION=
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
CONFLICTS+=		ssh-[0-9]* ssh6-[0-9]*
CONFLICTS+=		ssh2-[0-9]* ssh2-nox11-[0-9]*
CONFLICTS+=		openssh+gssapi-[0-9]*
CONFLICTS+=		lsh>2.0

USE_TOOLS+=		perl

CRYPTO=			yes

# retain the following line, for IPv6-ready pkgsrc webpage
BUILD_DEFS+=		USE_INET6

INSTALL_TARGET=		install-nokeys
PLIST_SRC=		# empty

.include "options.mk"

.if ${OPSYS} == "Interix"

# OpenSSH on Interix has some important caveats
MESSAGE_SRC=		${.CURDIR}/MESSAGE.Interix
BUILDLINK_PASSTHRU_DIRS+= /usr/local/include/bind /usr/local/lib/bind
CONFIGURE_ENV+=		ac_cv_func_openpty=no
CONFIGURE_ENV+=		ac_cv_type_struct_timespec=yes
CPPFLAGS+=		-I/usr/local/include/bind
LDFLAGS+=		-L/usr/local/lib/bind
LIBS+=			-lbind -ldb -lcrypt

.else # not Interix

PKG_USERS=		${OPENSSH_USER}:${OPENSSH_GROUP}:${OPENSSH_UID}:sshd\ privsep:${OPENSSH_CHROOT}:${NOLOGIN}
PKG_GROUPS=             ${OPENSSH_GROUP}:${OPENSSH_GID}

.endif

SSH_PID_DIR=		${VARBASE}/run	# default directory for PID files

PKG_SYSCONFSUBDIR=	ssh

USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-mantype=man
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-pid-dir=${SSH_PID_DIR}
CONFIGURE_ARGS+=	--with-ssl-dir=${SSLBASE}
CONFIGURE_ARGS+=	--with-tcp-wrappers=${BUILDLINK_PREFIX.tcp_wrappers}

.if ${OPSYS} != "Interix"
CONFIGURE_ARGS+=	--with-privsep-path=${OPENSSH_CHROOT}
CONFIGURE_ARGS+=	--with-privsep-user=${OPENSSH_USER}
.endif

# the openssh configure script finds and uses ${LD} if defined and
# defaults to ${CC} if not. we override LD here, since running the
# linker directly results in undefined symbols for obvious reasons.
#
CONFIGURE_ENV+=		LD=${CC:Q}

# Enable S/Key support on NetBSD, Darwin, and Solaris.
.if (${OPSYS} == "NetBSD") || (${OPSYS} == "Darwin") || (${OPSYS} == "SunOS")
.  include "../../security/skey/buildlink3.mk"
CONFIGURE_ARGS+=	--with-skey=${BUILDLINK_PREFIX.skey}
.else
CONFIGURE_ARGS+=	--without-skey
.endif

.if (${OPSYS} == "NetBSD") && exists(/usr/include/utmpx.h)
# if we have utmpx et al do not try to use login()
CONFIGURE_ARGS+=	--disable-libutil
.endif
.if (${OPSYS} == "SunOS") && (${OS_VERSION} == "5.8" || ${OS_VERSION} == "5.9")
CONFIGURE_ARGS+=	--disable-utmp --disable-wtmp
.endif
.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--enable-md5-password
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

# do the same for xauth
.if exists(${X11BASE}/bin/xauth)
CONFIGURE_ARGS+=	--with-xauth=${X11BASE}/bin/xauth
.else
CONFIGURE_ARGS+=	--with-xauth=${X11PREFIX}/bin/xauth
.endif

CONFS=			ssh_config sshd_config moduli

.if exists(/dev/urandom)
.  if ${OPSYS} == "NetBSD"
MESSAGE_SRC+=		${.CURDIR}/MESSAGE.urandom
.  endif
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
OWN_DIRS=		${OPENSSH_CHROOT}
RCD_SCRIPTS=		sshd

PLIST_SRC+=		${.CURDIR}/PLIST
FILES_SUBST+=		SSH_PID_DIR=${SSH_PID_DIR}

INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}; for file in ${CONFS}; do				\
		${INSTALL_DATA} $${file}.out ${EGDIR}/$${file};		\
	done
.if !empty(PKG_OPTIONS:Mpam) && ${OPSYS} == "Linux"
	${INSTALL_DATA} ${WRKSRC}/contrib/sshd.pam.generic ${EGDIR}/sshd.pam
.endif

.include "../../mk/bsd.pkg.mk"
