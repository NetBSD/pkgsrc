# $NetBSD: Makefile,v 1.273 2022/06/28 11:35:38 wiz Exp $

DISTNAME=		openssh-9.0p1
PKGNAME=		${DISTNAME:S/p1/.1/}
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_OPENBSD:=OpenSSH/portable/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.openssh.com/
COMMENT=		Open Source Secure shell client and server (remote login program)
LICENSE=		modified-bsd

CONFLICTS=		sftp-[0-9]*
CONFLICTS+=		ssh-[0-9]* ssh6-[0-9]*
CONFLICTS+=		ssh2-[0-9]* ssh2-nox11-[0-9]*
CONFLICTS+=		openssh+gssapi-[0-9]*
CONFLICTS+=		lsh>2.0
BROKEN_ON_PLATFORM+=	OpenBSD-*-*

USE_GCC_RUNTIME=	yes
USE_TOOLS+=		autoconf perl

# retain the following line, for IPv6-ready pkgsrc webpage
BUILD_DEFS+=		IPV6_READY

PKG_GROUPS_VARS+=	OPENSSH_GROUP
PKG_USERS_VARS+=	OPENSSH_USER
BUILD_DEFS+=		OPENSSH_CHROOT
BUILD_DEFS+=		VARBASE

INSTALL_TARGET=		install-nokeys

.include "options.mk"

# fixes: dyld: Symbol not found: _allow_severity
CONFIGURE_ARGS.Darwin+=	--disable-strip

PKG_GROUPS=		${OPENSSH_GROUP}
PKG_USERS=		${OPENSSH_USER}:${OPENSSH_GROUP}

PKG_GECOS.${OPENSSH_USER}=	sshd privsep pseudo-user
PKG_HOME.${OPENSSH_USER}=	${OPENSSH_CHROOT}

SSH_PID_DIR=		${VARBASE}/run	# default directory for PID files

PKG_SYSCONFSUBDIR=	ssh

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-mantype=man
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-pid-dir=${SSH_PID_DIR}
CONFIGURE_ARGS+=	--with-tcp-wrappers=${BUILDLINK_PREFIX.tcp_wrappers}

CONFIGURE_ARGS+=	--with-privsep-path=${OPENSSH_CHROOT:Q}
CONFIGURE_ARGS+=	--with-privsep-user=${OPENSSH_USER}

# pkgsrc already enforces a "secure" version of zlib via dependencies,
# so skip this bogus version check.
CONFIGURE_ARGS+=	--without-zlib-version-check

.if ${_PKGSRC_MKPIE} != "no"
CONFIGURE_ARGS+=	--with-pie
.endif

# the openssh configure script finds and uses ${LD} if defined and
# defaults to ${CC} if not. we override LD here, since running the
# linker directly results in undefined symbols for obvious reasons.
#
CONFIGURE_ENV+=		LD=${CC:Q}

# Enable S/Key support on NetBSD, Darwin, and Solaris.
.if (${OPSYS} == "NetBSD") || (${OPSYS} == "Darwin") || (${OPSYS} == "SunOS")
.  include "../../security/skey/buildlink3.mk"
.endif

.if (${OPSYS} == "NetBSD")
.  if exists(/usr/include/utmpx.h)
# if we have utmpx et al do not try to use login()
CONFIGURE_ARGS+=	--disable-libutil
.  endif
#
# NetBSD current after 2011/03/12 has incompatible strnvis(3) and
# prior version don't have it.  So, disable use of strnvis(3) now.
#
CONFIGURE_ENV+=		ac_cv_func_strnvis=no
#
# workaround for ./configure problem, pkg/50936
#
CONFIGURE_ENV+=		ac_cv_func_reallocarray=no
.endif

.if (${OPSYS} == "SunOS") && (${OS_VERSION} == "5.8" || ${OS_VERSION} == "5.9")
CONFIGURE_ARGS+=	--disable-utmp --disable-wtmp
.endif

CONFIGURE_ARGS.Linux+=	--enable-md5-password

# The ssh-askpass program is in ${X11BASE}/bin or ${PREFIX}/bin depending
# on if it's part of the X11 distribution, or if it's installed from pkgsrc
# (security/ssh-askpass).
#
.if exists(${X11BASE}/bin/ssh-askpass)
ASKPASS_PROGRAM=	${X11BASE}/bin/ssh-askpass
.else
ASKPASS_PROGRAM=	${PREFIX}/bin/ssh-askpass
.endif
CONFIGURE_ENV+=		ASKPASS_PROGRAM=${ASKPASS_PROGRAM:Q}
MAKE_ENV+=		ASKPASS_PROGRAM=${ASKPASS_PROGRAM:Q}

# do the same for xauth
.if exists(${X11BASE}/bin/xauth)
CONFIGURE_ARGS+=	--with-xauth=${X11BASE}/bin/xauth
.else
CONFIGURE_ARGS+=	--with-xauth=${PREFIX}/bin/xauth
.endif

CONFS=			ssh_config sshd_config moduli

PLIST_VARS+=		darwin

EGDIR=			${PREFIX}/share/examples/${PKGBASE}

# enable privsep patches
.if ${OPSYS} == "Darwin"
CONF_FILES+=		${EGDIR}/org.openssh.sshd.sb ${PKG_SYSCONFDIR}/org.openssh.sshd.sb
CPPFLAGS+=		-D__APPLE_SANDBOX_NAMED_EXTERNAL__
PLIST.darwin=		yes
.endif

.for f in ${CONFS}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
OWN_DIRS=		${OPENSSH_CHROOT}
RCD_SCRIPTS=		sshd
RCD_SCRIPT_SRC.sshd=	${WRKDIR}/sshd.sh
SMF_METHODS=		sshd

FILES_SUBST+=		SSH_PID_DIR=${SSH_PID_DIR}

SUBST_CLASSES+=		patch
SUBST_STAGE.patch=	pre-configure
SUBST_FILES.patch=	sandbox-darwin.c
SUBST_SED.patch=	-e '/channel_input_port_forward_request/s/0/ROOTUID/'
SUBST_VARS.patch=	PKG_SYSCONFDIR

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"

#
# type of key "ecdsa" isn't always supported depends on OpenSSL.
#
pre-configure:
	cd ${WRKSRC} && autoconf -i

post-configure:
	if ${EGREP} -q '^\#define[ 	]+OPENSSL_HAS_ECC' \
	    ${WRKSRC}/config.h; then \
		${SED} -e '/HAVE_ECDSA/s/.*//' \
			${FILESDIR}/sshd.sh > ${WRKDIR}/sshd.sh; \
	else \
		${SED} -e '/HAVE_ECDSA_START/,/HAVE_ECDSA_STOP/d' \
			${FILESDIR}/sshd.sh > ${WRKDIR}/sshd.sh; \
	fi
	${SED} -e 's,@VARBASE@,${VARBASE},g' \
		< ${FILESDIR}/org.openssh.sshd.sb.in \
		> ${WRKDIR}/org.openssh.sshd.sb

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	cd ${WRKSRC}; for file in ${CONFS}; do				\
		${INSTALL_DATA} $${file}.out ${DESTDIR}${EGDIR}/$${file};		\
	done
.if !empty(PKG_OPTIONS:Mpam) && ${OPSYS} == "Linux"
	${INSTALL_DATA} ${WRKSRC}/contrib/sshd.pam.generic \
	  ${DESTDIR}${EGDIR}/sshd.pam
.endif
.if ${OPSYS} == "Darwin"
	${INSTALL_DATA} ${WRKDIR}/org.openssh.sshd.sb \
		${DESTDIR}${EGDIR}/org.openssh.sshd.sb
.endif

.include "../../mk/bsd.pkg.mk"
