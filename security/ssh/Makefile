# New ports collection makefile for:	ssh
# Version required:     		1.2.22
# Date created:				19971214
# Whom:					hubertf@netbsd.org
#
# $NetBSD: Makefile,v 1.13 1998/03/10 16:18:28 frueauf Exp $
# FreeBSD Id: Makefile,v 1.47 1997/11/10 22:04:42 dima Exp
#
# Maximal ssh package requires a YES value for USE_PERL
# and USE_LIBWRAP.
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
# <bsd.port.mk> that test variables that may be set here.  Note that
# this inclusion is otherwise redundant, since <bsd.port.mk> includes
# <bsd.own.mk>, which includes it.

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

# You can set USA_RESIDENT appropriately in /etc/mk.conf if this bugs you..
USA_RESIDENT?=		NO

.if defined(USA_RESIDENT) && ${USA_RESIDENT} == YES
DISTFILES=		${DISTNAME}.tar.gz rsaref2.tar.gz
MASTER_SITES=	\
	ftp://ftp.funet.fi/pub/unix/security/login/ssh/ \
	ftp://nic.funet.fi/pub/crypt/mirrors/ftp.dsi.unimi.it/applied-crypto/ \
	ftp://rzsun2.informatik.uni-hamburg.de/pub/virus/crypt/ripem/ \
	ftp://idea.sec.dsi.unimi.it/pub/security/crypt/math/ \
	ftp://ftp.univie.ac.at/security/crypt/cryptography/asymmetric/rsa/ \
	ftp://isdec.vc.cvut.cz/pub/security/unimi/crypt/applied-crypto/
.endif

# Use SSH_CONF_DIR from /etc/mk.conf, if defined; otherwise default to /etc
SSH_CONF_DIR?=		/etc

CONFIGURE_ARGS+=	--prefix=${PREFIX} --with-etcdir=${SSH_CONF_DIR} \
			--disable-suid-ssh

#Uncomment if all your users are in their own group and their homedir
#is writeable by that group.  Beware the security implications!
#CONFIGURE_ARGS+= --enable-group-writeability

#Uncomment if you want to allow ssh to emulate an unencrypted rsh connection
#over a secure medium.  This is normally dangerous since it can lead to the
#disclosure keys and passwords.
#CONFIGURE_ARGS+=	--with-none

.if defined(USA_RESIDENT) && ${USA_RESIDENT} == YES
CONFIGURE_ARGS+=	--with-rsaref
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

# Support for libwrap.
.if defined(USE_LIBWRAP) && ${USE_LIBWRAP} == YES
CONFIGURE_ARGS+=	--with-libwrap
.endif

# Include SOCKS firewall support
.if defined(USE_SOCKS) && ${USE_SOCKS} == YES
CONFIGURE_ARGS+=	--with-socks="-L${PREFIX}/lib -lsocks5"
.endif

MAN1=			scp.1 ssh-add.1 ssh-agent.1 ssh-keygen.1 ssh.1 \
			make-ssh-known-hosts.1
MAN8=			sshd.8

pre-patch:
	@${MV} -f ${WRKSRC}/make-ssh-known-hosts.pl \
	    ${WRKSRC}/make-ssh-known-hosts.pl.in

fetch-depends:
.if !defined(USA_RESIDENT) || ${USA_RESIDENT} != YES && ${USA_RESIDENT} != NO
	@${ECHO}
	@${ECHO} You must set variable USA_RESIDENT to YES if you are a USA
	@${ECHO} resident or NO otherwise.
	@${ECHO} If you are a USA resident you have to get the RSAREF2
	@${ECHO} library \(RSA Inc. holds a patent on RSA and public key
	@${ECHO} cypto in general - using RSA implementations other than
	@${ECHO} RSAREF will violate the US patent law\)
	@${ECHO} and extract it to ${WRKSRC}.
	@${FALSE}
.endif

post-extract:
.if defined(USA_RESIDENT) && ${USA_RESIDENT} == YES
	@${MV} ${WRKDIR}/rsaref2 ${WRKSRC}/rsaref2
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
.if defined(MANZ)
	${RM} -f ${PREFIX}/man/man1/slogin.1.gz
	${LN} -sf ssh.1.gz ${PREFIX}/man/man1/slogin.1.gz
.else
	${RM} -f ${PREFIX}/man/man1/slogin.1
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

# Include <bsd.port.mk> here.  It is essential to have all the override
# targets precede inclusion of this.

.include <bsd.port.mk>

# Following stuff must be after <bsd.port.mk> to expand
# exists(${PREFIX}) properly

.if defined(USE_PERL) && ${USE_PERL} == YES || \
    exists(${PREFIX}/bin/perl5.00404) && \
    (!defined(USE_PERL) || ${USE_PERL} != NO)
BUILD_DEPENDS+=		perl5.00404:${PORTSDIR}/lang/perl5
CONFIGURE_ENV+=		PERL=${PREFIX}/bin/perl5.00404
.else
CONFIGURE_ENV+=		PERL=/replace_it_with_PERL_path
.endif
