# $NetBSD: Makefile,v 1.2 2002/09/19 09:04:26 jlam Exp $
#

DISTNAME=	ssh-3.2.0
PKGNAME=	${DISTNAME:C/ssh-/ssh2-/}
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.ssh.com/pub/ssh/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ssh.com
COMMENT=	Secure Shell client and server for V.2 SSH protocol

CONFLICTS=	openssh-[0-9]* ssh6-[0-9]* ssh-[0-9]* sftp-[0-9]*

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES
PKG_SYSCONFSUBDIR=	ssh2

BUILD_DEFS+=		USE_INET6

CRYPTO=			YES

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS:M*BSD} == "") && (${OPSYS} != "Linux")
LICENSE=		no-commercial-use
.endif

SSH_PID_DIR=		/var/run	# default directory for PID files
SSH_PID_DIR.SunOS=      /etc		# Solaris doesn't have a /var/run

.if defined(SSH_PID_DIR.${OPSYS})
SSH_PID_DIR=		${SSH_PID_DIR.${OPSYS}}
.endif

CONFIGURE_ARGS+=	--without-daemonpam --without-clientpam
CONFIGURE_ARGS+=	--without-ssh-agent1-compat
CONFIGURE_ARGS+=	--without-ssh1-compat
CONFIGURE_ARGS+=	--with-libwrap=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-pid-dir=${SSH_PID_DIR}
# Setting FOREIGN_ETCDIR to PKG_SYSCONFBASE may seem stupid
# if PKG_SYSCONFDIR.${PKG_SYSCONFVAR} is set but it does no harm...
CONFIGURE_ARGS+=	--with-foreign-etcdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}

MAKE_ENV+=		PKGBASE=${PKGBASE}

RCD_SCRIPTS=		ssh2_secure_shell

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
EGFILES=		ext_authorization_example.sh \
			kbdint_plugin_example.sh

CONFS=			sshd2_config ssh2_config ssh_dummy_shell.out
CONF_FILES=		# empty
.for FILE in ${CONFS}
CONF_FILES+=		${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}
.endfor
FILES_SUBST=		SSH_PID_DIR=${SSH_PID_DIR}

OWN_DIRS=		${PKG_SYSCONFDIR}/knownhosts
OWN_DIRS+=		${PKG_SYSCONFDIR}/hostkeys

DOCSDIR=		${PREFIX}/share/doc/${PKGBASE}
DOCS=			CHANGES FAQ HOWTO.anonymous.sftp INSTALL LICENSE \
			NEWS README REGEX-SYNTAX SSH2.QUICKSTART \
			RFC.authorization_program_protocol \
			RFC.kbdint_plugin_protocol

post-install:
	${INSTALL_DATA_DIR} ${DOCSDIR}
.for FILE in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.for FILE in ${EGFILES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${EGDIR}
.endfor

.include "../../security/tcp_wrappers/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
