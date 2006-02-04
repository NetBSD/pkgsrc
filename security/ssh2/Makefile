# $NetBSD: Makefile,v 1.13 2006/02/04 00:33:17 wiz Exp $

DISTNAME=	ssh-3.2.9.1
PKGNAME=	${DISTNAME:C/ssh-/ssh2-/}
PKGREVISION=	4
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.ssh.com/pub/ssh/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ssh.com/
COMMENT=        Secure Shell client and server for V.2 SSH protocol

CONFLICTS+=	openssh-[0-9]* ssh6-[0-9]* ssh-[0-9]* sftp-[0-9]*
CONFLICTS+=	openssh+gssapi-[0-9]* ssh2-nox11-[0-9]*

GNU_CONFIGURE=		YES

BUILD_DEFS+=		USE_INET6

CRYPTO=			YES
PKG_SYSCONFSUBDIR=	ssh2

DISTINFO_FILE=		${.CURDIR}/../../security/ssh2/distinfo
PATCHDIR=		${.CURDIR}/../../security/ssh2/patches
FILESDIR=		${.CURDIR}/../../security/ssh2/files
PLIST_SRC=		${.CURDIR}/../../security/ssh2/PLIST

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS:M*BSD} == "") && (${OPSYS} != "Linux")
LICENSE=		no-commercial-use
.endif

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

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/${PKGBASE}
.endfor
	${INSTALL_DATA_DIR} ${EGDIR}
.for file in ${EGFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${EGDIR}
.endfor

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
