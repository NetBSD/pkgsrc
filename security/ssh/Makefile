# $NetBSD: Makefile,v 1.38 1999/01/30 20:15:19 is Exp $
# FreeBSD Id: Makefile,v 1.47 1997/11/10 22:04:42 dima Exp
#

DISTNAME=		ssh-1.2.26
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.cs.hut.fi/pub/ssh/ \
			ftp://ftp.funet.fi/pub/unix/security/login/ssh/ \
			ftp://ftp.cert.dfn.de/pub/tools/net/ssh/

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.cs.hut.fi/ssh/

CONFLICTS=		ssh-1.2.22 ssh-1.2.23 ssh-1.2.25

RESTRICTED=		"Crypto; export-controlled"
MIRROR_DISTFILE=	no
IS_INTERACTIVE=		YES

CFLAGS=			-O2
GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

# Use SSH_CONF_DIR from /etc/mk.conf, if defined; otherwise default to /etc
SSH_CONF_DIR?=		/etc

CONFIGURE_ARGS+=	--with-etcdir=${SSH_CONF_DIR} --with-libwrap

#Uncomment if all your users are in their own group and their homedir
#is writeable by that group.  Beware the security implications!
#CONFIGURE_ARGS+=	--enable-group-writeability

#Uncomment if you want to allow ssh to emulate an unencrypted rsh connection
#over a secure medium.  This is normally dangerous since it can lead to the
#disclosure keys and passwords.
#CONFIGURE_ARGS+=	--with-none

.if defined(USE_RSAREF2) && ${USE_RSAREF2} == YES
DEPENDS+=		rsaref-2.0:../../security/rsaref
CONFIGURE_ARGS+=	--with-rsaref="${LOCALBASE}/lib"
CONFIGURE_ENV+=		LDFLAGS="-Wl,-R${LOCALBASE}/lib"
CFLAGS+=		-I${LOCALBASE}/include
.endif

# Include support for the SecureID card
# Warning: untested !
.if defined(USE_SECUREID) && ${USE_SECUREID} == YES
CONFIGURE_ARGS+=	--with-secureid
.endif

# Don't use IDEA. IDEA can be freely used for non-commercial use. However,
# commercial use may require a license in a number of countries
# Warning: untested !
.if defined(DONT_USE_IDEA) && ${DONT_USE_IDEA} == YES
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

PKGDIR=		${WRKDIR}/pkg

pre-patch:
	@${MV} -f ${WRKSRC}/make-ssh-known-hosts.pl \
	    ${WRKSRC}/make-ssh-known-hosts.pl.in

fetch-depends:
.if !defined(USE_RSAREF2) || ${USE_RSAREF2} != YES && ${USE_RSAREF2} != NO
	@${ECHO}
        @${ECHO} The variable USE_RSAREF2 must be set to either YES or NO
        @${ECHO} in order to build this package.  USA residents that are
        @${ECHO} no licensees of the RSA algorithm MUST set this variable
        @${ECHO} to YES.  Users outside the USA MUST set this variable to
        @${ECHO} NO.  Licensees may choose -- NO is faster.
	@${ECHO}
	@${ECHO} You may also want to set DONT_USE_IDEA to YES if this program
	@${ECHO} will be used for a commercial purpose.  There are other
	@${ECHO} configure options\; look at the pkg Makefile for more info.
	@${FALSE}
.endif

post-extract:
	@${MKDIR} ${PKGDIR}
.for FILE in COMMENT DEINSTALL DESCR MESSAGE PLIST
	@${SED} -e 's#@SSH_CONF_DIR@#${SSH_CONF_DIR}#g' \
	  -e 's#@PREFIX@#${PREFIX}#g' \
	  <${.CURDIR}/pkg/${FILE} >${PKGDIR}/${FILE}
.endfor
	@if [ -f ${X11BASE}/include/X11/X.h ]; then \
		${ECHO} bin/ssh-askpass >>${PKGDIR}/PLIST; \
		${ECHO} bin/ssh-askpass1 >>${PKGDIR}/PLIST; \
	fi

post-build:
	@${SED} -e 's#@SSH_CONF_DIR@#${SSH_CONF_DIR}#g' \
	  -e 's#@PREFIX@#${PREFIX}#g' \
	  <${FILESDIR}/sshd.sh >${WRKDIR}/sshd.sh

post-install:
	@${MKDIR} ${PREFIX}/share/examples/ssh
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
	${INSTALL_SCRIPT} ${WRKDIR}/sshd.sh ${PREFIX}/etc/rc.d/sshd.sh

# Include <bsd.pkg.mk> here.  It is essential to have all the override
# targets precede inclusion of this.

.include "../../mk/bsd.pkg.mk"
