# $NetBSD: options.mk,v 1.32 2013/03/24 20:10:31 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qmail
PKG_OPTIONS_OPTIONAL_GROUPS=	rcpt
PKG_OPTIONS_GROUP.rcpt=	qmail-badrcptto qmail-qregex qmail-realrcptto
PKG_SUPPORTED_OPTIONS+=	sasl syncdir tls qmail-bigdns qmail-netqmail
PKG_SUPPORTED_OPTIONS+=	qmail-outgoingip qmail-viruscan

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqmail-badrcptto)
BADRCPTTO_PATCH=	badrcptto.patch
PATCHFILES+=		${BADRCPTTO_PATCH}
SITES.${BADRCPTTO_PATCH}=	http://patch.be/qmail/
PATCH_DIST_STRIP.${BADRCPTTO_PATCH}=	-p1
.endif

.if !empty(PKG_OPTIONS:Mqmail-bigdns)
BIGDNS_PATCH=		qmail-103.patch
PATCHFILES+=		${BIGDNS_PATCH}
SITES.${BIGDNS_PATCH}=	http://www.ckdhr.com/ckd/
PATCH_DIST_STRIP.${BIGDNS_PATCH}=	-p1
.endif

.if !empty(PKG_OPTIONS:Mqmail-netqmail)
DISTNAME=		netqmail-1.06
.endif

.if !empty(PKG_OPTIONS:Mqmail-outgoingip)
OUTGOINGIP_PATCH=	outgoingip.patch
PATCHFILES+=		${OUTGOINGIP_PATCH}
SITES.${OUTGOINGIP_PATCH}=	http://www.qmail.org/
.endif

PLIST_VARS+=		qregex
.if !empty(PKG_OPTIONS:Mqmail-qregex)
QREGEX_PATCH=		qregex-20060423.patch
PATCHFILES+=		${QREGEX_PATCH}
SITES.${QREGEX_PATCH}=	http://www.arda.homeunix.net/store/qmail/
PATCH_DIST_STRIP.${QREGEX_PATCH}=	-p3
PLIST.qregex=		yes
.endif

.if !empty(PKG_OPTIONS:Mqmail-realrcptto)
REALRCPTTO_PATCH=	qmail-1.03-realrcptto-2006.12.10.patch
PATCHFILES+=		${REALRCPTTO_PATCH}
SITES.${REALRCPTTO_PATCH}=	http://code.dogmap.org/qmail/
PATCH_DIST_STRIP.${REALRCPTTO_PATCH}=	-p1
.endif

PLIST_VARS+=		tls
.if !empty(PKG_OPTIONS:Msasl) || !empty(PKG_OPTIONS:Mtls)
.  if empty(PKG_OPTIONS:Msasl)
PKG_OPTIONS+=		sasl
.  endif
.  include "../../security/openssl/buildlink3.mk"
TLSSASL_PATCH=		netqmail-1.05-tls-smtpauth-20070321.patch
PATCHFILES+=		${TLSSASL_PATCH}
SITES.${TLSSASL_PATCH}=	http://shupp.org/patches/
.  if !empty(PKG_OPTIONS:Mtls)
CFLAGS+=		-DTLS=20060104	# NOTE: update according to the patch
DJB_INSTALL_TARGETS=	cert tmprsadh
USE_TOOLS+=		gmake
PLIST.tls=		yes
.  endif
.endif

.if !empty(PKG_OPTIONS:Msyncdir)
.  include "../../devel/syncdir/buildlink3.mk"
SUBST_CLASSES+=		load
SUBST_STAGE.load=	do-configure
SUBST_FILES.load=	make-load.sh
SUBST_SED.load=		-e '$$s|$$| ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.syncdir}/lib -L${BUILDLINK_PREFIX.syncdir}/lib \-lsyncdir|'
.  if ${OPSYS} == "Darwin"
SUBST_SED.load+=	-e '$$s|$$| -bind_at_load|'
.  endif
SUBST_MESSAGE.load=	Setting linker flags for syncdir.
.endif

.if !empty(PKG_OPTIONS:Mqmail-viruscan)
VIRUSCAN_PATCH=		qmail-smtpd-viruscan-1.3.patch
VIRUSCAN_LOG_PATCH=	qmail-smtpd-viruscan-logging.patch
PATCHFILES+=		${VIRUSCAN_PATCH} ${VIRUSCAN_LOG_PATCH}
SITES.${VIRUSCAN_PATCH}=	http://www.qmail.org/
SITES.${VIRUSCAN_LOG_PATCH}=	${MASTER_SITE_LOCAL}
PATCH_DIST_STRIP.${VIRUSCAN_PATCH}=	-p1
PATCH_DIST_STRIP.${VIRUSCAN_LOG_PATCH}=	-p1
SUBST_CLASSES+=		viruscan
SUBST_STAGE.viruscan=	do-configure
SUBST_FILES.viruscan=	qmail-smtpd.c
SUBST_SED.viruscan=	-e 's|qmail-smtpd: ||g'
VIRUSCAN_SIGS_SRCFILE=	${DISTDIR}/${VIRUSCAN_PATCH}
.else
VIRUSCAN_SIGS_SRCFILE=	# undefined
.endif
