# $NetBSD: Makefile,v 1.12 2000/05/31 15:32:44 itojun Exp $
#

DISTNAME=		openssh-2.1.0p3
CATEGORIES=		security
MASTER_SITES=		http://the.wiretapped.net/security/cryptography/ssh/OpenSSH/files/ \
			http://www.firedrake.org/openssh/files/ \
			ftp://thermo.stat.ncsu.edu/pub/openssh/files/ \
			ftp://sunsite.cnlab-switch.ch/mirror/OpenSSH/files/ \
			ftp://ftp.openssh.com/pub/OpenBSD/OpenSSH/portable/old/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.openssh.com/

BUILD_DEPENDS+=		${LOCALBASE}/bin/perl:../../lang/perl5
BUILD_DEPENDS+=		autoreconf:../../devel/autoconf

.if !exists(/usr/include/openssl/rsa.h)
DEPENDS+=		openssl-[0-9]*:../../security/openssl
.endif

CONFLICTS=		ssh-[0-9]* ssh6-[0-9]*

# retain the following line, for IPv6-ready pkgsrc webpage 
BUILD_DEFS+=		USE_INET6

# USE_PERL5=		yes
RESTRICTED=		"Crypto; export-controlled"
MIRROR_DISTFILE=	no
DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
MESSAGE_FILE=		${WRKDIR}/MESSAGE
PLIST_SRC=		${WRKDIR}/PLIST
BUILD_DEFS+=		SSH_CONF_DIR

# matches what's in `Configure' (except sparc64)
ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 \
			NetBSD-*-m68k NetBSD-*-mips NetBSD-*-mipseb \
			NetBSD-*-mipsel NetBSD-*-ns32k NetBSD-*-powerpc \
			NetBSD-*-sparc NetBSD-*-vax

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	openssl

.include "../../mk/bsd.prefs.mk"
SSH_CONF_DIR?=		/etc
CONFIGURE_ARGS=		--sysconfdir=${SSH_CONF_DIR}

pre-configure:
	cd ${WRKSRC}; autoreconf

post-build:
	cd ${PKGDIR}; \
	for FILE in DEINSTALL MESSAGE PLIST ${FILESDIR}/sshd.sh; do \
	  ${SED} -e 's#@SSH_CONF_DIR@#${SSH_CONF_DIR}#g' \
	         -e 's#@PREFIX@#${PREFIX}#g' \
		 <$${FILE} >${WRKDIR}/`basename $${FILE}`; \
	done

post-install:
	for FILE in ssh_config sshd_config ; do \
		if [ ! -f ${SSH_CONF_DIR}/$${FILE} ]; then \
			${INSTALL_DATA} ${PREFIX}/share/examples/ssh/$${FILE} ${SSH_CONF_DIR}/$${FILE}  ; \
		fi ; \
	done
	if [ ! -f ${SSH_CONF_DIR}/ssh_host_key ]; then \
		${ECHO} "Generating a secret host key..."; \
		${PREFIX}/bin/ssh-keygen \
			-f ${SSH_CONF_DIR}/ssh_host_key -N ""; \
	fi
	${INSTALL_SCRIPT} ${WRKDIR}/sshd.sh ${PREFIX}/etc/rc.d/sshd.sh

.include "../../mk/bsd.pkg.mk"
