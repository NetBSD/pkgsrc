# $NetBSD: options.mk,v 1.41 2017/05/22 17:18:32 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qmail
PKG_OPTIONS_OPTIONAL_GROUPS=	rcpt
PKG_OPTIONS_GROUP.rcpt=	qmail-badrcptto qmail-qregex
PKG_OPTIONS_GROUP.rcpt+=qmail-rcptcheck qmail-realrcptto
PKG_SUPPORTED_OPTIONS+=	sasl syncdir tls qmail-bigdns qmail-maildiruniq
PKG_SUPPORTED_OPTIONS+=	qmail-netqmail qmail-outgoingip qmail-remote
PKG_SUPPORTED_OPTIONS+=	qmail-srs qmail-viruscan
PKG_SUGGESTED_OPTIONS+=	qmail-bigdns qmail-netqmail qmail-realrcptto

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
SITES.${BIGDNS_PATCH}+=	${MASTER_SITE_LOCAL}
PATCH_DIST_STRIP.${BIGDNS_PATCH}=	-p1
.endif

.if !empty(PKG_OPTIONS:Mqmail-maildiruniq)
MAILDIRUNIQ_PATCH=	qmail-1.03-maildir-uniq.patch
PATCHFILES+=		${MAILDIRUNIQ_PATCH}
SITES.${MAILDIRUNIQ_PATCH}=	http://www.memoryhole.net/qmail/
PATCH_DIST_STRIP.${MAILDIRUNIQ_PATCH}=	-p1
.endif

.if !empty(PKG_OPTIONS:Mqmail-netqmail)
DISTNAME=		netqmail-1.06
.endif

.if !empty(PKG_OPTIONS:Mqmail-outgoingip)
OUTGOINGIP_PATCH=	outgoingip.patch
PATCHFILES+=		${OUTGOINGIP_PATCH}
SITES.${OUTGOINGIP_PATCH}=	http://www.qmail.org/
.endif

.if !empty(PKG_OPTIONS:Mqmail-remote)
REMOTE_PATCH=		netqmail-1.06-qmailremote-20170522.patch
PATCHFILES+=		${REMOTE_PATCH}
SITES.${REMOTE_PATCH}=	https://schmonz.com/2017/05/22/
.endif

PLIST_VARS+=		srs
.PHONY: post-extract-srs post-install-srs
.if !empty(PKG_OPTIONS:Mqmail-srs)
.  include "../../mail/libsrs2/buildlink3.mk"
SRS_PATCH=		qmail-srs-0.8.patch
PATCHFILES+=		${SRS_PATCH}
SITES.${SRS_PATCH}=	http://www.mco2.com.br/opensource/download/qmail/
PATCH_DIST_STRIP.${SRS_PATCH}=	-p1
.  if !empty(PKG_OPTIONS:Mqmail-netqmail)
PATCH_DIST_STRIP.${SRS_PATCH}+=	-l
SUBST_CLASSES+=		srsnetq1 srsnetq2
SUBST_STAGE.srsnetq1=	pre-patch
SUBST_STAGE.srsnetq2=	post-patch
SUBST_FILES.srsnetq1=	Makefile
SUBST_FILES.srsnetq2=	Makefile
SUBST_SED.srsnetq1=	-e 's|^auto_split.o env.a$$|auto_split.o|'
SUBST_SED.srsnetq2=	-e 's|^auto_split.o$$|auto_split.o env.a|'
SUBST_SED.srsnetq1+=	-e 's|^	substdio.a error.a str.a fs.a auto_qmail.o auto_split.o env.a$$|	substdio.a error.a str.a fs.a auto_qmail.o auto_split.o|'
SUBST_SED.srsnetq2+=	-e 's|^	substdio.a error.a str.a fs.a auto_qmail.o auto_split.o \\$$|	substdio.a error.a str.a fs.a auto_qmail.o auto_split.o env.a \\|'
.  endif
SUBST_CLASSES+=		srsinclude
SUBST_STAGE.srsinclude=	do-configure
SUBST_FILES.srsinclude=	srs.c
SUBST_SED.srsinclude=	-e 's|/usr/local/include/srs2.h|srs2.h|'
SUBST_CLASSES+=		srsreadme
SUBST_STAGE.srsreadme=	do-configure
SUBST_FILES.srsreadme=	README.srs
SUBST_SED.srsreadme=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR:Q},g'
SPECIAL_PERMS+=		${PREFIX}/bin/srsfilter ${QMAIL_ROOT_USER} ${QMAIL_QMAIL_GROUP} 0755
PLIST.srs=		yes
MESSAGE_SRC+=		${PKGDIR}/MESSAGE.srs
post-extract-srs:
	${CP} ${FILESDIR}/README.srs ${WRKSRC}
post-install-srs:
	${INSTALL_DATA} ${WRKSRC}/README.srs ${DESTDIR}${DOCDIR}
.else
post-extract-srs:
	${DO_NADA}
post-install-srs:
	${DO_NADA}
.endif

PLIST_VARS+=		qregex
.if !empty(PKG_OPTIONS:Mqmail-qregex)
QREGEX_PATCH=		qregex-20060423.patch
PATCHFILES+=		${QREGEX_PATCH}
SITES.${QREGEX_PATCH}=	http://www.arda.homeunix.net/store/qmail/
# actually http://www.arda.homeunix.net/?ddownload=409
PATCH_DIST_STRIP.${QREGEX_PATCH}=	-p3
PLIST.qregex=		yes
.endif

.if !empty(PKG_OPTIONS:Mqmail-rcptcheck)
RCPTCHECK_PATCH=	qmail-smtpd.patch
PATCHFILES+=		${RCPTCHECK_PATCH}
SITES.${RCPTCHECK_PATCH}=	http://www.soffian.org/downloads/qmail/
PATCH_DIST_STRIP.${RCPTCHECK_PATCH}=	-p1
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
TLSSASL_PATCH=		netqmail-1.05-tls-smtpauth-20070417.patch
PATCHFILES+=		${TLSSASL_PATCH}
SITES.${TLSSASL_PATCH}=	https://raw.githubusercontent.com/shupp/legacy-qmail-related/master/patches/
.  if !empty(PKG_OPTIONS:Mtls)
CFLAGS+=		-DTLS=20070408	# NOTE: match what's _in_ the patch
USE_TOOLS+=		openssl
SUBST_CLASSES+=		tmprsadh
SUBST_STAGE.tmprsadh=	do-configure
SUBST_FILES.tmprsadh=	update_tmprsadh.sh
SUBST_SED.tmprsadh=	-e 's|^export PATH=.*||'
SUBST_SED.tmprsadh+=	-e 's|^openssl |${OPENSSL} |'
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

PLIST_VARS+=		viruscan
.PHONY: post-extract-viruscan post-install-viruscan
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
PLIST.viruscan=		yes
post-extract-viruscan:
	${SED} -e '1,15d' -e '34,$$d'		\
		< ${DISTDIR}/${VIRUSCAN_PATCH}	\
		> ${WRKSRC}/signatures
	${CHMOD} 644 ${WRKSRC}/signatures
post-install-viruscan:
	${INSTALL_DATA} ${WRKSRC}/signatures ${DESTDIR}/${EGDIR}/control
.  for i in control/signatures
CONF_FILES+=		${EGDIR}/${i} ${PKG_SYSCONFDIR}/${i}
.  endfor
.else
post-extract-viruscan:
	${DO_NADA}
post-install-viruscan:
	${DO_NADA}
.endif
