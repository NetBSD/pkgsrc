# $NetBSD: Makefile,v 1.31 2000/11/09 09:18:23 itojun Exp $
#

DISTNAME=		openssh-2.3.0p1
CATEGORIES=		security
MASTER_SITES=		http://the.wiretapped.net/security/cryptography/ssh/OpenSSH/files/ \
			http://www.firedrake.org/openssh/files/ \
			ftp://thermo.stat.ncsu.edu/pub/openssh/files/ \
			ftp://sunsite.cnlab-switch.ch/mirror/OpenSSH/files/ \
			ftp://gd.tuwien.ac.at/OpenBSD/OpenSSH/portable/ \
			ftp://ftp.openssh.com/pub/OpenBSD/OpenSSH/portable/ \
			ftp://ftp.openssh.com/pub/OpenBSD/OpenSSH/portable/old/
# Don't delete the last entry -- it's there if the pkgsrc version is not
# up-to-date and the mirrors already removed the old distfile.

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.openssh.com/

BUILD_DEPENDS+=		${PERL5}:../../lang/perl5-base
BUILD_DEPENDS+=		autoreconf:../../devel/autoconf

CRYPTO=			yes

# Check for a usable installed version of OpenSSL.  Version must be greater
# than 0.9.5a.  If a usable version isn't present, then use the pkgsrc
# OpenSSL package.
#
.if exists(/usr/include/openssl/rsa.h)
OPENSSLV_H=		/usr/include/openssl/opensslv.h
OPENSSL_VERSION!=	awk '/.*OPENSSL_VERSION_NUMBER.*/ { print $$3 }' \
				${OPENSSLV_H}
OPENSSL_VERSION_095a=	0x0090581fL
.if (${OPENSSL_VERSION} != ${OPENSSL_VERSION_095a})
DEPENDS+=		openssl-0.9.5a:../../security/openssl
SSLBASE=		${LOCALBASE}
.else
SSLBASE=		/usr
.endif
.else
DEPENDS+=		openssl-0.9.5a:../../security/openssl
SSLBASE=		${LOCALBASE}
.endif

CONFLICTS=		ssh-[0-9]* ssh6-[0-9]*

# retain the following line, for IPv6-ready pkgsrc webpage 
BUILD_DEFS+=		USE_INET6
BUILD_DEFS+=		SSH_CONF_DIR

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL
MESSAGE_FILE=		${WRKDIR}/MESSAGE

# matches what's in `Configure' (except sparc64 and alpha, see PR 10984)
ONLY_FOR_PLATFORM=	NetBSD-*-arm32 NetBSD-*-i386 \
			NetBSD-*-m68k NetBSD-*-mips NetBSD-*-mipseb \
			NetBSD-*-mipsel NetBSD-*-ns32k NetBSD-*-powerpc \
			NetBSD-*-sparc NetBSD-*-vax

.include "../../mk/bsd.prefs.mk"

SSH_CONF_DIR?=		/etc

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${SSH_CONF_DIR}
CONFIGURE_ARGS+=	--with-ssl-dir=${SSLBASE}

# The ssh-askpass program is in ${X11BASE}/bin or ${X11PREFIX}/bin depending
# on if it's part of the X11 distribution, or if it's installed from pkgsrc
# (security/ssh-askpass).
#
.if exists(${X11BASE}/bin/ssh-askpass)
MAKE_ENV+=		ASKPASS_LOCATION=${X11BASE}/bin
.else
MAKE_ENV+=		ASKPASS_LOCATION=${X11PREFIX}/bin
.endif

pre-configure:
	cd ${WRKSRC} && autoreconf

post-build:
	for FILE in \
		${PKGDIR}/DEINSTALL	\
		${PKGDIR}/INSTALL	\
		${PKGDIR}/MESSAGE	\
		${FILESDIR}/sshd.sh;	\
	do \
		${SED}	-e 's#@SSH_CONF_DIR@#${SSH_CONF_DIR}#g' \
			-e 's#@PREFIX@#${PREFIX}#g' \
			< $${FILE} > ${WRKDIR}/`basename $${FILE}`; \
	done

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/sshd.sh ${PREFIX}/etc/rc.d/sshd
	PKG_PREFIX=${PREFIX} ${SH} ${REQ_FILE} ${PKGNAME} INSTALL
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
