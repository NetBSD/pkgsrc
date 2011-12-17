# $NetBSD: Makefile,v 1.25 2011/12/17 23:42:59 sbd Exp $

DISTNAME=	ssh-3.2.9.1
PKGNAME=	${DISTNAME:C/ssh-/ssh2-/}
PKGREVISION=	8
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.ssh.com/pub/ssh/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ssh.com/
LICENSE=	ssh-communications-security-license

RESTRICTED=		Reciprocal grant required for derivative works.  Non-comercial use restrictions on some systems.
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

MAKE_JOBS_SAFE=		no

COMMENT=	Secure Shell client and server for V.2 SSH protocol

PKG_DESTDIR_SUPPORT=	destdir

CONFLICTS+=		openssh-[0-9]* ssh6-[0-9]* ssh-[0-9]* sftp-[0-9]*
CONFLICTS+=		openssh+gssapi-[0-9]* ssh2-nox11-[0-9]*

GNU_CONFIGURE=		YES

BUILD_DEFS+=		IPV6_READY

CRYPTO=			YES
PKG_SYSCONFSUBDIR=	ssh2

DISTINFO_FILE=		${.CURDIR}/../../security/ssh2/distinfo
PATCHDIR=		${.CURDIR}/../../security/ssh2/patches
FILESDIR=		${.CURDIR}/../../security/ssh2/files
PLIST_SRC=		${.CURDIR}/../../security/ssh2/PLIST

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "sparc64"
# Later we may want to put an upper version bound on OS_VERSION or on
# gcc version for this.
CONFIGURE_ARGS+=	--disable-compiler-optimizations
.endif

SSH_PID_DIR=		/var/run	# default directory for PID files
.if ${OPSYS} == "SunOS" && !empty(OS_VERSION:M5.[012345678])
SSH_PID_DIR=		/etc		# Older Solaris doesn't have a /var/run
.endif

CONFIGURE_ARGS+=	--without-daemonpam --without-clientpam
CONFIGURE_ARGS+=	--without-ssh-agent1-compat
CONFIGURE_ARGS+=	--without-ssh1-compat
CONFIGURE_ARGS+=	--with-libwrap=${BUILDLINK_PREFIX.tcp-wrappers}
CONFIGURE_ARGS+=	--with-pid-dir=${SSH_PID_DIR:Q}

# This seems to break x11 forwarding at least on NetBSD 3.1 amd64
# and i386, so I assume it actually breaks it for all platforms.
# (i.e ssh localhost xterm does not work as client will get wrong
# auth cookie).
# Without this it will use the xauth method and that will work.
CONFIGURE_ARGS+=	--without-x11-security

# Setting FOREIGN_ETCDIR to PKG_SYSCONFBASEDIR may seem stupid
# if PKG_SYSCONFDIR.${PKG_SYSCONFVAR} is set but it does no harm...
#
CONFIGURE_ARGS+=	--with-foreign-etcdir=${PKG_SYSCONFBASEDIR:Q}
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR:Q}

MAKE_ENV+=		PKGBASE=${PKGBASE:Q}
MAKE_ENV+=		RM=${RM:Q}

RCD_SCRIPTS=		ssh2_secure_shell

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
EGFILES=		ext_authorization_example.sh \
			kbdint_plugin_example.sh

CONFS=			sshd2_config ssh2_config ssh_dummy_shell.out
CONF_FILES=		# empty
.for file in ${CONFS}
CONF_FILES+=		${EGDIR}/${file} ${PKG_SYSCONFDIR}/${file}
.endfor
FILES_SUBST+=		SSH_PID_DIR=${SSH_PID_DIR:Q}

OWN_DIRS=		${PKG_SYSCONFDIR}/knownhosts
OWN_DIRS+=		${PKG_SYSCONFDIR}/hostkeys

DOCS=			CHANGES FAQ HOWTO.anonymous.sftp INSTALL LICENSE \
			NEWS README REGEX-SYNTAX SSH2.QUICKSTART \
			RFC.authorization_program_protocol \
			RFC.kbdint_plugin_protocol

TEST_TARGET=		check

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${PREFIX:Q}/share/doc/${PKGBASE}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR:Q}${PREFIX:Q}/share/doc/${PKGBASE}
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${EGDIR:Q}
.for file in ${EGFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR:Q}${EGDIR:Q}
.endfor

.include "../../mk/termcap.buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
