# $NetBSD: Makefile,v 1.95 2001/12/05 16:03:57 agc Exp $
# FreeBSD Id: Makefile,v 1.47 1997/11/10 22:04:42 dima Exp
#

# We do not upgrade to 1.2.28 and beyond, intentionally.  There was license
# change between 1.2.27 and 1.2.28, and the new license prohibits us from
# modifying/redistributing it.
#
DISTNAME=		ssh-1.2.27
PKGREVISION=		1
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.ssh.com/pub/ssh/old/ \
			ftp://ftp.funet.fi/pub/unix/security/login/ssh/ \
			ftp://ftp.cert.dfn.de/pub/tools/net/ssh/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.cs.hut.fi/ssh/
COMMENT=		Secure shell client and server (remote login program)

CONFLICTS=		openssh-[0-9]* ssh6-[0-9]*

CRYPTO=			YES
LICENSE=		no-commercial-use
USE_RSAREF2=		NO

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
# the next line is needed if you have the gmp package installed
LDFLAGS+=		-Lgmp-2.0.2-ssh-2
GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

# Use SSH_CONF_DIR from /etc/mk.conf, if defined; otherwise default to /etc
SSH_CONF_DIR?=		/etc

CONFIGURE_ARGS+=	--with-etcdir=${SSH_CONF_DIR}

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-libwrap
.endif

.if ${OPSYS} == "SunOS"
DEPENDS+=		zlib-[0-9]*:../../devel/zlib
CONFIGURE_ENV+=		X_CFLAGS="-I${LOCALBASE}/include"
.endif

#Uncomment if all your users are in their own group and their homedir
#is writeable by that group.  Beware the security implications!
#CONFIGURE_ARGS+=	--enable-group-writeability

#Uncomment if you want to allow ssh to emulate an unencrypted rsh connection
#over a secure medium.  This is normally dangerous since it can lead to the
#disclosure keys and passwords.
#CONFIGURE_ARGS+=	--with-none

.if defined(USE_RSAREF2) && ${USE_RSAREF2} == YES
DEPENDS+=		rsaref-2.0p3:../../security/rsaref
CONFIGURE_ARGS+=	--with-rsaref="${LOCALBASE}/lib"
CONFIGURE_ENV+=		LDFLAGS="-Wl,-R${LOCALBASE}/lib"
CFLAGS+=		-I${LOCALBASE}/include
.endif

# Include support for the SecureID card
# Warning: untested !
.if defined(USE_SECUREID) && ${USE_SECUREID} == YES
CONFIGURE_ARGS+=	--with-secureid
.endif

# If rsh is elsewhere to /usr/bin/rsh
.if defined(SSH_RSHPATH)
CONFIGURE_ARGS+=       --with-rsh=${SSH_RSHPATH}
.endif

# By default, use IDEA.  IDEA can be freely used for non-commercial use.
# However, commercial use may require a license in a number of countries.
#
USE_IDEA?=		YES

# Handle deprecated option SSH_DONT_USE_IDEA.
#
.if defined(SSH_DONT_USE_IDEA) && ${SSH_DONT_USE_IDEA} == YES
USE_IDEA=		NO
.endif

.if ${USE_IDEA} != "YES"
CONFIGURE_ARGS+=	--without-idea
.endif

# Include SOCKS firewall support
.if defined(USE_SOCKS) && (${USE_SOCKS} == 4 || ${USE_SOCKS} == 5)
CONFIGURE_ARGS+= 	--with-socks${USE_SOCKS}="-L${LOCALBASE}/lib -lsocks${USE_SOCKS}"
CFLAGS+=	 	-I${LOCALBASE}/include
.if ${USE_SOCKS} == 4
DEPENDS+=		socks4-2.2:../../net/socks4
.else
DEPENDS+=		socks5-1.0.2:../../net/socks5
.endif
.endif

# The original Kerberos v4 patches were fetched from
# http://www.monkey.org/~dugsong/ssh-afs/
# PATCH_SITES+=		ftp://ftp.monkey.org/pub/users/dugsong/
# PATCHFILES+=		ssh-1.2.27-afs-kerberos.patch-1
# MD5 (ssh-1.2.27-afs-kerberos.patch-1) = d440f74958d9c3805b76dbc13e97e87d

.if defined(KERBEROS)
USE_KERBEROS=		yes
CONFIGURE_ARGS+=	--with-krb4=/usr
.endif

# XXX KERBEROS 5 SUPPORT BROKEN WITH HEIMDAL
#.if defined(KERBEROS) && ${KERBEROS} == 5
#USE_KERBEROS=	yes
#CONFIGURE_ARGS+=--with-krb5=/usr
#.else
#CONFIGURE_ARGS+=--without-krb5
#.endif

# Find X11 libraries with xpkgwedge
.if defined(USE_LOCALBASE_FOR_X11)
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include
.endif

# Enable support for TIS authentication server
.if defined(USE_TIS) && ${USE_TIS} == YES
CONFIGURE_ARGS+=	--with-tis=${LOCALBASE}
.endif

# Don't install "ssh" setuid
.if !defined(SSH_SUID) || ${SSH_SUID} != YES
CONFIGURE_ARGS+=	--disable-suid-ssh
.endif

# Make libwrap also compare against forwards (off by default)
.if defined(LIBWRAP_FWD) && ${LIBWRAP_FWD} == YES
CFLAGS+=		-DLIBWRAP_FWD
.endif

# be more effective on M68060 machines
.if defined(M68060)
CONFIGURE_ARGS+=	--disable-asm
CFLAGS+=		-m68060
.endif

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
PLIST_SRC=	${WRKDIR}/PLIST
PLIST_SUBST+=	INSTALL="${INSTALL}"		\
		ROOT_GROUP="${ROOT_GROUP}"
MESSAGE_SUBST+=	SSH_CONF_DIR="${SSH_CONF_DIR}"

pre-patch:
	@${MV} -f ${WRKSRC}/make-ssh-known-hosts.pl \
	    ${WRKSRC}/make-ssh-known-hosts.pl.in
	@# SSH DES and AFS/Kerberos DES conflict.
	@${MV} -f ${WRKSRC}/des.h ${WRKSRC}/ssh-des.h

fetch-depends:
.if !defined(USE_RSAREF2) || ${USE_RSAREF2} != YES && ${USE_RSAREF2} != NO
	@${ECHO}
	@${ECHO} The variable USE_RSAREF2 must be set to either YES or NO
	@${ECHO} in order to build this package.  USA residents that are
	@${ECHO} not licensees of the RSA algorithm MUST set this variable
	@${ECHO} to YES.  Users outside the USA MUST set this variable to
	@${ECHO} NO.  Licensees may choose -- NO is faster.
	@${ECHO}
	@${ECHO} You may also want to set USE_IDEA to NO if this program
	@${ECHO} will be used for a commercial purpose.  There are other
	@${ECHO} configure options\; look at the pkg Makefile for more info.
	@${FALSE}
.endif

post-patch:
	@# Make sure that "automake" is never run.
	@${FIND} ${WRKSRC} -name Makefile.in -print | ${XARGS} ${TOUCH} ${TOUCH_FLAGS}

post-build:
	@cd ${PKGDIR}; \
	for FILE in DEINSTALL PLIST ${FILESDIR}/sshd.sh; do \
	  ${SED} -e 's#@SSH_CONF_DIR@#${SSH_CONF_DIR}#g' \
	    -e 's#@PREFIX@#${PREFIX}#g' \
	    <$${FILE} >${WRKDIR}/`basename $${FILE}`; \
	done
	@if [ -x ${WRKSRC}/ssh-askpass ]; then \
	  ${ECHO} bin/ssh-askpass >>${PLIST_SRC}; \
	  ${ECHO} bin/ssh-askpass1 >>${PLIST_SRC}; \
	fi

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ssh
	@${MKDIR} ${WRKDIR}${SSH_CONF_DIR}
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} \
		-f ${MAKEFILE} install_prefix=${WRKDIR} install-configs)
	${INSTALL_DATA} ${WRKDIR}${SSH_CONF_DIR}/ssh_config \
		${WRKDIR}${SSH_CONF_DIR}/sshd_config ${PREFIX}/share/examples/ssh
	@${RM} -rf ${WRKDIR}${SSH_CONF_DIR}
	@if [ ! -f ${SSH_CONF_DIR}/ssh_host_key ]; then \
		${ECHO} "Generating a secret host key..."; \
		${PREFIX}/bin/ssh-keygen \
			-f ${SSH_CONF_DIR}/ssh_host_key -N ""; \
	fi
	${INSTALL_SCRIPT} ${WRKDIR}/sshd.sh ${PREFIX}/etc/rc.d/sshd

BUILD_DEFS+=		USE_IDEA SSH_CONF_DIR SSH_SUID USE_RSAREF2
BUILD_DEFS+=		LIBWRAP_FWD M68060 USE_SOCKS

.include "../../mk/bsd.pkg.mk"
