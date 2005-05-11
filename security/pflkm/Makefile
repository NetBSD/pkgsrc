# $NetBSD: Makefile,v 1.7 2005/05/11 22:01:28 peter Exp $

DISTNAME=		pflkm-20050511
CATEGORIES=		security ipv6
MASTER_SITES=		http://nedbsd.nl/~ppostma/pf/

MAINTAINER=		peter@pointless.nl
HOMEPAGE=		http://nedbsd.nl/~ppostma/pf/
COMMENT=		OpenBSD Packet Filter as loadable kernel module for NetBSD

ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-*

USE_PKGINSTALL=		yes
NO_CONFIGURE=		yes

PKG_USERS=		_pflogd:nogroup::pflogd\\ pseudo-user:${VARBASE}/chroot/pflogd:/sbin/nologin

RCD_SCRIPTS=		pf pflogd
PKG_SYSCONFSUBDIR=	pf
CONF_FILES=		${PREFIX}/share/examples/${PKGBASE}/pf.conf \
			${PKG_SYSCONFDIR}/pf.conf
CONF_FILES+=		${PREFIX}/share/examples/${PKGBASE}/pf.os \
			${PKG_SYSCONFDIR}/pf.os
CONF_FILES_MODE=	0600

OWN_DIRS=		${VARBASE}/chroot/pflogd
OWN_DIRS+=		${PREFIX}/share/examples/${PKGBASE}
INSTALLATION_DIRS=	lkm include/net

PKG_OPTIONS_VAR=	PKG_OPTIONS.pf
PKG_SUPPORTED_OPTIONS=	altq ifevents

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.prefs.mk"

.if !empty(PKG_OPTIONS:Maltq)
# Check if the kernel source was patched.
_IS_PATCHED_!=	${GREP} -c altq_pfattach ${NETBSDSRCDIR}/sys/altq/altq_subr.c || ${TRUE}
.if ${_IS_PATCHED_} == "1"
MAKE_ENV+=		ALTQ=yes
.else
PKG_FAIL_REASON+=	"It appears that you didn't applied the ALTQ patch to your kernel sources."
PKG_FAIL_REASON+=	"Please see: http://nedbsd.nl/~ppostma/pf/\#altq"
.endif
.endif

.if !empty(PKG_OPTIONS:Mifevents)
# Check if the kernel source was patched.
_IS_PATCHED_!=	${GREP} -c if_event_add ${NETBSDSRCDIR}/sys/net/if.c || ${TRUE}
.if ${_IS_PATCHED_} == "1"
MAKE_ENV+=		IFEVENTS=yes
.else
PKG_FAIL_REASON+=	"It appears that you didn't applied the if_events patch to your kernel sources."
PKG_FAIL_REASON+=	"Please see: http://nedbsd.nl/~ppostma/pf/\#if_events"
.endif
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/pf.conf \
		${PREFIX}/share/examples/${PKGBASE}/pf.conf
	${INSTALL_DATA} ${WRKSRC}/etc/pf.os \
		${PREFIX}/share/examples/${PKGBASE}/pf.os

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/net/if_pflog.h ${PREFIX}/include/net/if_pflog.h
	${INSTALL_DATA} ${WRKSRC}/include/net/if_pfsync.h ${PREFIX}/include/net/if_pfsync.h
	${INSTALL_DATA} ${WRKSRC}/include/net/pfvar.h ${PREFIX}/include/net/pfvar.h
	${INSTALL_PROGRAM} ${WRKSRC}/libexec/ftp-proxy/ftp-proxy ${PREFIX}/libexec/ftp-proxy
	${INSTALL_MAN} ${WRKSRC}/libexec/ftp-proxy/ftp-proxy.cat8 ${PREFIX}/man/cat8/ftp-proxy.0
	${INSTALL_MAN} ${WRKSRC}/libexec/ftp-proxy/ftp-proxy.8 ${PREFIX}/man/man8/ftp-proxy.8
	${INSTALL_DATA} ${WRKSRC}/lkm/pf.o ${PREFIX}/lkm/pf.o
	${INSTALL_MAN} ${WRKSRC}/man/pf.cat4 ${PREFIX}/man/cat4/pf.0
	${INSTALL_MAN} ${WRKSRC}/man/pflog.cat4 ${PREFIX}/man/cat4/pflog.0
	${INSTALL_MAN} ${WRKSRC}/man/pfsync.cat4 ${PREFIX}/man/cat4/pfsync.0
	${INSTALL_MAN} ${WRKSRC}/man/pf.conf.cat5 ${PREFIX}/man/cat5/pf.conf.0
	${INSTALL_MAN} ${WRKSRC}/man/pf.os.cat5 ${PREFIX}/man/cat5/pf.os.0
	${INSTALL_MAN} ${WRKSRC}/man/pf.4 ${PREFIX}/man/man4/pf.4
	${INSTALL_MAN} ${WRKSRC}/man/pflog.4 ${PREFIX}/man/man4/pflog.4
	${INSTALL_MAN} ${WRKSRC}/man/pfsync.4 ${PREFIX}/man/man4/pfsync.4
	${INSTALL_MAN} ${WRKSRC}/man/pf.conf.5 ${PREFIX}/man/man5/pf.conf.5
	${INSTALL_MAN} ${WRKSRC}/man/pf.os.5 ${PREFIX}/man/man5/pf.os.5
	${INSTALL_PROGRAM} ${WRKSRC}/sbin/pfctl/pfctl ${PREFIX}/sbin/pfctl
	${INSTALL_MAN} ${WRKSRC}/sbin/pfctl/pfctl.cat8 ${PREFIX}/man/cat8/pfctl.0
	${INSTALL_MAN} ${WRKSRC}/sbin/pfctl/pfctl.8 ${PREFIX}/man/man8/pfctl.8
	${INSTALL_PROGRAM} ${WRKSRC}/sbin/pflogd/pflogd ${PREFIX}/sbin/pflogd
	${INSTALL_MAN} ${WRKSRC}/sbin/pflogd/pflogd.cat8 ${PREFIX}/man/cat8/pflogd.0
	${INSTALL_MAN} ${WRKSRC}/sbin/pflogd/pflogd.8 ${PREFIX}/man/man8/pflogd.8
	${INSTALL_PROGRAM} ${WRKSRC}/usr.sbin/authpf/authpf ${PREFIX}/sbin/authpf
	${INSTALL_MAN} ${WRKSRC}/usr.sbin/authpf/authpf.cat8 ${PREFIX}/man/cat8/authpf.0
	${INSTALL_MAN} ${WRKSRC}/usr.sbin/authpf/authpf.8 ${PREFIX}/man/man8/authpf.8
	${INSTALL_PROGRAM} ${WRKSRC}/usr.sbin/tcpdump/pftcpdump ${PREFIX}/sbin/pftcpdump
	${INSTALL_MAN} ${WRKSRC}/usr.sbin/tcpdump/pftcpdump.cat8 ${PREFIX}/man/cat8/pftcpdump.0
	${INSTALL_MAN} ${WRKSRC}/usr.sbin/tcpdump/pftcpdump.8 ${PREFIX}/man/man8/pftcpdump.8

SUBST_CLASSES=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	man/pfsync.4 man/pf.conf.5
SUBST_FILES.path+=	sbin/pfctl/pfctl.8 sbin/pfctl/pfctl_parser.h
SUBST_FILES.path+=	usr.sbin/authpf/authpf.8 usr.sbin/authpf/pathnames.h
SUBST_SED.path=		-e 's,/etc/pf.os,${PKG_SYSCONFDIR}/pf.os,g'
SUBST_SED.path+=	-e 's,/etc/pf.conf,${PKG_SYSCONFDIR}/pf.conf,g'
SUBST_SED.path+=	-e 's,/etc/authpf/authpf.conf,${PKG_SYSCONFDIR}/authpf.conf,g'
SUBST_SED.path+=	-e 's,/etc/authpf/authpf.allow,${PKG_SYSCONFDIR}/authpf.allow,g'
SUBST_SED.path+=	-e 's,/etc/authpf/authpf.rules,${PKG_SYSCONFDIR}/authpf.rules,g'
SUBST_SED.path+=	-e 's,/etc/authpf/authpf.problem,${PKG_SYSCONFDIR}/authpf.problem,g'
SUBST_SED.path+=	-e 's,/etc/authpf/authpf.message,${PKG_SYSCONFDIR}/authpf.message,g'
SUBST_SED.path+=	-e 's,/etc/authpf/users,${PKG_SYSCONFDIR}/users,g'
SUBST_SED.path+=	-e 's,/etc/authpf/banned,${PKG_SYSCONFDIR}/banned,g'
SUBST_SED.path+=	-e 's,/usr/sbin/authpf,${PREFIX}/sbin/authpf,g'
SUBST_SED.path+=	-e 's,/sbin/pfctl,${PREFIX}/sbin/pfctl,g'
SUBST_MESSAGE.path=	"Fixing hardcoded dirs."

.include "../../mk/bsd.pkg.mk"
