# $NetBSD: options.mk,v 1.16 2005/10/05 04:28:00 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qmail
PKG_SUPPORTED_OPTIONS+=	darwin sasl syncdir tls qmail-badrcptto qmail-bigdns
PKG_SUPPORTED_OPTIONS+=	qmail-netqmail qmail-outgoingip qmail-qregex
PKG_SUPPORTED_OPTIONS+=	qmail-realrcptto qmail-viruscan

.if ${OPSYS} == "Darwin"
PKG_SUGGESTED_OPTIONS=	darwin
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqmail-badrcptto)
BADRCPTTO_PATCH=	badrcptto.patch
PATCHFILES+=		${BADRCPTTO_PATCH}
SITES_${BADRCPTTO_PATCH}=	http://patch.be/qmail/
PATCH_DIST_STRIP.${BADRCPTTO_PATCH}=	-p2
.endif

.if !empty(PKG_OPTIONS:Mqmail-bigdns)
BIGDNS_PATCH=		qmail-103.patch
PATCHFILES+=		${BIGDNS_PATCH}
SITES_${BIGDNS_PATCH}=	http://www.ckdhr.com/ckd/
PATCH_DIST_STRIP.${BIGDNS_PATCH}=	-p1
.endif

.if !empty(PKG_OPTIONS:Mdarwin)
DARWIN_PATCH=		panther.patch
PATCHFILES+=		${DARWIN_PATCH}
SITES_${DARWIN_PATCH}=	http://http.netdevice.com:9080/qmail/patch/
PATCH_DIST_STRIP.${DARWIN_PATCH}=	-p1
post-wrapper:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	nameser8_compat_h="include/nameser8_compat.h";			\
	if [ ! -e /usr/$${nameser8_compat_h} ]; then			\
		${TOUCH} ${BUILDLINK_DIR}/$${nameser8_compat_h};	\
	fi
DARWINSUFX=		.doc
.else
DARWINSUFX=		# empty
.endif
PLIST_SUBST+=		DARWINSUFX=${DARWINSUFX}

.if !empty(PKG_OPTIONS:Mqmail-netqmail)
NETQMAIL_PATCH=		netqmail-1.05.tar.gz
PATCHFILES+=		${NETQMAIL_PATCH}
PATCH_DIST_CAT.${NETQMAIL_PATCH}=	${CAT} ${WRKSRC}/../${DISTNAME}.patch
PATCH_DIST_STRIP.${NETQMAIL_PATCH}=	-p1
.endif

.if !empty(PKG_OPTIONS:Mqmail-outgoingip)
OUTGOINGIP_PATCH=	outgoingip.patch
PATCHFILES+=		${OUTGOINGIP_PATCH}
SITES_${OUTGOINGIP_PATCH}=	http://www.qmail.org/
.endif

.if !empty(PKG_OPTIONS:Mqmail-qregex)
QREGEX_PATCH=		qregex-20040725.patch
PATCHFILES+=		${QREGEX_PATCH}
SITES_${QREGEX_PATCH}=	http://www.arda.homeunix.net/store/qmail/
PATCH_DIST_STRIP.${QREGEX_PATCH}=	-p3
PLIST_SRC+=             ${PKGDIR}/PLIST.qregex
.endif

.if !empty(PKG_OPTIONS:Mqmail-realrcptto)
REALRCPTTO_PATCH=	qmail-1.03-realrcptto-2004.08.20.patch
PATCHFILES+=		${REALRCPTTO_PATCH}
SITES_${REALRCPTTO_PATCH}=	http://code.dogmap.org/qmail/
PATCH_DIST_STRIP.${REALRCPTTO_PATCH}=	-p1
.endif

.if !empty(PKG_OPTIONS:Msasl) || !empty(PKG_OPTIONS:Mtls)
.  if empty(PKG_OPTIONS:Msasl)
PKG_OPTIONS+=		sasl
.  endif
.  include "../../security/openssl/buildlink3.mk"
TLSSASL_PATCH=		netqmail-1.05-tls-smtpauth-20040705.patch
PATCHFILES+=            ${TLSSASL_PATCH}
SITES_${TLSSASL_PATCH}=	http://shupp.org/patches/
.  if !empty(PKG_OPTIONS:Mtls)
CFLAGS+=		-DTLS=20040419			# from the patch
DJB_INSTALL_TARGETS=	cert tmprsadh
USE_TOOLS+=		gmake
PLIST_SRC+=             ${PKGDIR}/PLIST.tls
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
SUBST_MESSAGE.load=	"Setting linker flags for syncdir."
.endif

.if !empty(PKG_OPTIONS:Mqmail-viruscan)
VIRUSCAN_PATCH=		qmail-smtpd-viruscan-1.3.patch
VIRUSCAN_LOG_PATCH=	qmail-smtpd-viruscan-logging.patch
PATCHFILES+=		${VIRUSCAN_PATCH} ${VIRUSCAN_LOG_PATCH}
SITES_${VIRUSCAN_PATCH}=http://www.qmail.org/
SITES_${VIRUSCAN_LOG_PATCH}=	http://scriptkitchen.com/qmail/
PATCH_DIST_STRIP.${VIRUSCAN_PATCH}=	-p1
PATCH_DIST_STRIP.${VIRUSCAN_LOG_PATCH}=	-p1
VIRUSCAN_SIGS_SRCFILE=	${DISTDIR}/${VIRUSCAN_PATCH}
.else
VIRUSCAN_SIGS_SRCFILE=	# undefined
.endif
