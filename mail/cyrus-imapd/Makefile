# $NetBSD: Makefile,v 1.1.1.1 2000/08/25 12:35:40 veego Exp $

DISTNAME=		cyrus-imapd-1.6.24
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://asg.web.cmu.edu/cyrus/imapd/

DEPENDS+=		tcl-8.0.5:../../lang/tcl80
DEPENDS+=		cyrus-sasl-1.5.24:../../mail/cyrus-sasl

ONLY_FOR_PLATFORM=	NetBSD-1.5*-* \
			SunOS-*-*

USE_PERL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-cyrus-prefix=${PREFIX}/cyrus
CONFIGURE_ARGS+=	--with-statedir=/var/run
CONFIGURE_ARGS+=	--enable-netscapehack
CONFIGURE_ARGS+=	--with-auth=unix
CONFIGURE_ARGS+=	--without-krb
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=-I${PREFIX}/include/cyrus-sasl

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL

CYRUS_USER?=	cyrus
CYRUS_GROUP?=	mail

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-cyrus-user=${CYRUS_USER}
CONFIGURE_ARGS+=	--with-cyrus-group=${CYRUS_GROUP}

.if (${OPSYS} == "NetBSD") && exists(/usr/include/krb5/com_err.h)
CPPFLAGS+=-I/usr/include/krb5
.endif

.if defined(KERBEROS) && ${KERBEROS} == 4
USE_KERBEROS=		yes
CONFIGURE_ARGS+=	--with-login=krb
.endif

.if !exists(/usr/include/openssl/rc4.h)
DEPENDS+=	openssl-0.9.*:../../security/openssl
CPPFLAGS+=-I${PREFIX}/include
.endif

.if ${OPSYS} == "NetBSD"
.if exists(/usr/sbin/user)
ADDUSER=	/usr/sbin/useradd
ADDGROUP=	/usr/sbin/groupadd
.else
DEPENDS+=	user>=20000313:../../sysutils/user
ADDUSER=	${LOCALBASE}/sbin/useradd
ADDGROUP=	${LOCALBASE}/sbin/groupadd
.endif
.elif ${OPSYS} == "SunOS"
ADDUSER=	useradd
ADDGROUP=	groupadd
.endif

pre-install:
	${SED}  -e 's|@CYUSER@|${CYRUS_USER}|g' \
		-e 's|@CYGROUP@|${CYRUS_GROUP}|g' \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}  -e 's|@CYUSER@|${CYRUS_USER}|g' \
		-e 's|@CYGROUP@|${CYRUS_GROUP}|g' \
		-e 's|@ADDUSER@|${ADDUSER}|g' \
		-e 's|@ADDGROUP@|${ADDGROUP}|g' \
		-e 's|@CHGRP@|${CHGRP}|g' \
		-e 's|@ID@|${ID}|g' \
		-e 's|@TOUCH@|${TOUCH}|g' \
		-e 's|@RM@|${RM}|g' \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

# Deliver must be executable by all on machines with local
# users sending to cyrus mailboxes.

#post-install:
#	@${CHMOD} a+rx ${PREFIX}/cyrus/bin/deliver

.include "../../mk/bsd.pkg.mk"
