# $NetBSD: Makefile,v 1.17 1998/04/22 14:22:48 agc Exp $
# FreeBSD Id: Makefile,v 1.47 1997/11/10 22:04:42 dima Exp
#

DISTNAME=		ssh-1.2.22
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.cs.hut.fi/pub/ssh/ \
			ftp://ftp.funet.fi/pub/unix/security/login/ssh/

MAINTAINER=		mrg@eterna.com.au

RESTRICTED=		"Crypto; export-controlled"
MIRROR_DISTFILE=	no
IS_INTERACTIVE=		YES

CFLAGS=			-O2
GNU_CONFIGURE=		YES

# Include local make config file here.  It is essential to have this
# precede any override targets (those that override defaults in
# <bsd.pkg.mk> that test variables that may be set here.  Note that
# this inclusion is otherwise redundant, since <bsd.pkg.mk> includes
# <bsd.own.mk>, which includes it.
# XXX: FIXME ! We need a simple way of doing this in many dozen pkgs.

OPSYS!= uname -s
.if (${OPSYS} == "FreeBSD")
.if exists(/etc/make.conf)
.include "/etc/make.conf"
.endif
.else
.if exists(/etc/mk.conf)
.include "/etc/mk.conf"
.endif
.endif

# Use SSH_CONF_DIR from /etc/mk.conf, if defined; otherwise default to /etc
SSH_CONF_DIR?=		/etc

CONFIGURE_ARGS+=	--prefix=${PREFIX} --with-etcdir=${SSH_CONF_DIR} \
			--disable-suid-ssh --with-libwrap

#Uncomment if all your users are in their own group and their homedir
#is writeable by that group.  Beware the security implications!
#CONFIGURE_ARGS+=	--enable-group-writeability

#Uncomment if you want to allow ssh to emulate an unencrypted rsh connection
#over a secure medium.  This is normally dangerous since it can lead to the
#disclosure keys and passwords.
#CONFIGURE_ARGS+=	--with-none

.if defined(USE_RSAREF2) && ${USE_RSAREF2} == YES
DEPENDS+=		rsaref-2.0:../../security/rsaref
CONFIGURE_ARGS+=	--with-rsaref="${PREFIX}/lib"
CFLAGS+=		-I${PREFIX}/include
.endif

# Include support for the SecureID card
# Warning: untested !
.if defined(USE_SECUREID) && ${USE_SECUREID} == YES
CONFIGURE_ARGS+=	--with-secureid
.endif

# Don't use IDEA. IDEA can be freely used for non-commercial use. However,
# commercial use may require a licence in a number of countries
# Warning: untested !
.if defined(DONT_USE_IDEA) && ${DONT_USE_IDEA} == YES
CONFIGURE_ARGS+=	--without-idea
.endif

# Include SOCKS firewall support
.if defined(USE_SOCKS) && ${USE_SOCKS} == YES
CONFIGURE_ARGS+= 	--with-socks="-L${PREFIX}/lib -lsocks5"
CFLAGS+=	 	-I${PREFIX}/include
.endif

# Make libwrap also compare against forwards (off by default)
.if defined(LIBWRAP_FWD) && ${LIBWRAP_FWD} == YES
CFLAGS+=		-DLIBWRAP_FWD
.endif

MAN1=			scp.1 ssh-add.1 ssh-agent.1 ssh-keygen.1 ssh.1 \
			make-ssh-known-hosts.1
MAN8=			sshd.8

pre-patch:
	@${MV} -f ${WRKSRC}/make-ssh-known-hosts.pl \
	    ${WRKSRC}/make-ssh-known-hosts.pl.in

fetch-depends:
.if !defined(USE_RSAREF2) || ${USE_RSAREF2} != YES && ${USE_RSAREF2} != NO
	@${ECHO}
	@${ECHO} The variable USE_RSAREF2 must be set to either YES or NO
	@${ECHO} in order to build this package.  USA residents not at the
	@${ECHO} Massachusetts Institute of Technology MUST set this
	@${ECHO} variable to YES.  Users outside the USA MUST set this
	@${ECHO} variable to NO.  People at MIT may choose -- NO is faster.
	@${ECHO}
	@${ECHO} You may also want to set DONT_USE_IDEA to YES if this program
	@${ECHO} will be used for a commercial purpose.  There are other
	@${ECHO} configure options\; look at the pkg Makefile for more info.
	@${FALSE}
.endif

pre-install:
	@${CAT} ${PKGDIR}/PLIST.pre | ${SED} \
		-e 's;\<\$$SSH_CONF_DIR\>;'${SSH_CONF_DIR}';g' \
		> ${PKGDIR}/PLIST
	@${CAT} ${PKGDIR}/MESSAGE.pre | ${SED} \
		-e 's;\<\$$SSH_CONF_DIR\>;'${SSH_CONF_DIR}';g' \
		-e 's;\<\$$PREFIX\>;'${PREFIX}';g' \
		> ${PKGDIR}/MESSAGE
	@${CAT} ${PKGDIR}/DEINSTALL.pre | ${SED} \
		-e 's;\<\$$SSH_CONF_DIR\>;'${SSH_CONF_DIR}';g' \
		> ${PKGDIR}/DEINSTALL

post-install:
	@${MKDIR} ${PREFIX}/share/examples/ssh
	@${MKDIR} ${WRKDIR}${SSH_CONF_DIR}
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} \
		${MAKEFILE} install_prefix=${WRKDIR} install-configs)
	${INSTALL_DATA} ${WRKDIR}${SSH_CONF_DIR}/ssh_config \
		${WRKDIR}${SSH_CONF_DIR}/sshd_config ${PREFIX}/share/examples/ssh
	@if [ ! -f ${SSH_CONF_DIR}/ssh_host_key ]; then \
		${ECHO} "Generating a secret host key..."; \
		${PREFIX}/bin/ssh-keygen \
			-f ${SSH_CONF_DIR}/ssh_host_key -N ""; \
	fi
	${RM} -f ${PREFIX}/man/man1/slogin.1 ${PREFIX}/man/man1/slogin.1.gz
.if defined(MANZ)
	${LN} -sf ssh.1.gz ${PREFIX}/man/man1/slogin.1.gz
.else
	${LN} -sf ssh.1 ${PREFIX}/man/man1/slogin.1
.endif
#	@if [ ! -f ${PREFIX}/etc/rc.d/sshd.sh ]; then \
#		${ECHO} "Installing ${PREFIX}/etc/rc.d/sshd.sh startup file."; \
#		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/sshd.sh; \
#		${ECHO} "[ -f ${SSH_CONF_DIR}/ssh_host_key ] || ${PREFIX}/bin/ssh-keygen -f ${SSH_CONF_DIR}/ssh_host_key -N ''" >> ${PREFIX}/etc/rc.d/sshd.sh; \
#		${ECHO} "[ -x ${PREFIX}/sbin/sshd ] && ${PREFIX}/sbin/sshd && ${ECHO} -n ' sshd'" >> ${PREFIX}/etc/rc.d/sshd.sh; \
#		chmod 755 ${PREFIX}/etc/rc.d/sshd.sh; \
#	fi
	@${CAT} ${PKGDIR}/MESSAGE

pre-clean:
	@${RM} -f ${PKGDIR}/PLIST ${PKGDIR}/MESSAGE ${PKGDIR}/DEINSTALL

# Include <bsd.pkg.mk> here.  It is essential to have all the override
# targets precede inclusion of this.

.include "../../mk/bsd.pkg.mk"
