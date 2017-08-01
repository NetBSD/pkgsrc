# $NetBSD: options.mk,v 1.44 2017/08/01 02:53:59 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.qmail
PKG_SUPPORTED_OPTIONS+=		eai qmail-rejectutils qmail-srs sasl syncdir tls
PKG_SUGGESTED_OPTIONS+=		eai qmail-rejectutils sasl syncdir tls

# For users migrating from 2017Q2; remove compatibility after 2017Q3 is branched
QMAIL_PATCHES_ALWAYS_ON=	netqmail bigdns maildiruniq outgoingip rcptcheck remote
QMAIL_PATCHES_REMOVED=		badrcptto qregex realrcptto viruscan
PKG_OPTIONS_ALWAYS_ON=		${QMAIL_PATCHES_ALWAYS_ON:S/^/qmail-/}
PKG_OPTIONS_REMOVED=		${QMAIL_PATCHES_REMOVED:S/^/qmail-/}
PKG_SUPPORTED_OPTIONS+=		${PKG_OPTIONS_ALWAYS_ON} ${PKG_OPTIONS_REMOVED}

# Formerly optional patches, now unconditionally applied:
QMAILPATCHES=			netqmail:${DEFAULT_DISTFILES}

QMAILPATCHES+=			tls-smtpauth:${TLSSASL_PATCH}
TLSSASL_PATCH=			netqmail-1.05-tls-smtpauth-20070417.patch
PATCHFILES+=			${TLSSASL_PATCH}
SITES.${TLSSASL_PATCH}=		https://raw.githubusercontent.com/shupp/legacy-qmail-related/master/patches/

QMAILPATCHES+=			bigdns:${BIGDNS_PATCH}
BIGDNS_PATCH=			qmail-103.patch
PATCHFILES+=			${BIGDNS_PATCH}
SITES.${BIGDNS_PATCH}=		http://www.ckdhr.com/ckd/
SITES.${BIGDNS_PATCH}+=		${MASTER_SITE_LOCAL}
PATCH_DIST_STRIP.${BIGDNS_PATCH}=-p1

QMAILPATCHES+=			destdir:${DESTDIR_PATCH}
DESTDIR_PATCH=			netqmail-1.06-destdir-20170716.patch
PATCHFILES+=			${DESTDIR_PATCH}
SITES.${DESTDIR_PATCH}=		https://schmonz.com/qmail/destdir/

QMAILPATCHES+=			maildiruniq:${MAILDIRUNIQ_PATCH}
MAILDIRUNIQ_PATCH=		qmail-1.03-maildir-uniq.patch
PATCHFILES+=			${MAILDIRUNIQ_PATCH}
SITES.${MAILDIRUNIQ_PATCH}=	http://www.memoryhole.net/qmail/
PATCH_DIST_STRIP.${MAILDIRUNIQ_PATCH}=-p1

QMAILPATCHES+=			outgoingip:${OUTGOINGIP_PATCH}
OUTGOINGIP_PATCH=		outgoingip.patch
PATCHFILES+=			${OUTGOINGIP_PATCH}
SITES.${OUTGOINGIP_PATCH}=	http://www.qmail.org/

QMAILPATCHES+=			rcptcheck:${RCPTCHECK_PATCH}
RCPTCHECK_PATCH=		netqmail-1.06-tls-smtpauth-20070417-rcptcheck-20170716.patch
PATCHFILES+=			${RCPTCHECK_PATCH}
SITES.${RCPTCHECK_PATCH}=	https://schmonz.com/qmail/rcptcheck/

QMAILPATCHES+=			remote:${REMOTE_PATCH}
REMOTE_PATCH=			netqmail-1.06-qmailremote-20170716.patch
PATCHFILES+=			${REMOTE_PATCH}
SITES.${REMOTE_PATCH}=		https://schmonz.com/qmail/remote/

.include "../../mk/bsd.options.mk"

# For users migrating from 2017Q2; remove compatibility after 2017Q3 is branched
.for i in ${PKG_OPTIONS_ALWAYS_ON}
.  if !empty(PKG_OPTIONS:M${i})
PKG_LEGACY_OPTIONS+=		${i}
PKG_OPTIONS_DEPRECATED_WARNINGS+="WARN: Please unset \"${i}\" option (it's now always enabled)."
.  endif
.endfor

# For users migrating from 2017Q2; remove compatibility after 2017Q3 is branched
.for i in ${PKG_OPTIONS_REMOVED}
.  if !empty(PKG_OPTIONS:M${i})
PKG_LEGACY_OPTIONS+=		${i}
PKG_OPTIONS_DEPRECATED_WARNINGS+="WARN: Please unset \"${i}\" option (it's now always included, as a program)."
.  endif
.endfor

.if !empty(PKG_OPTIONS:Meai)
.  include "../../devel/libidn2/buildlink3.mk"
QMAILPATCHES+=			eai:${EAI_PATCH}
EAI_PATCH=			qmail-smtputf8.patch
PATCHFILES+=			${EAI_PATCH}
SITES.${EAI_PATCH}=		http://arnt.gulbrandsen.priv.no/qmail/
PATCH_DIST_CAT.${EAI_PATCH}=	${SED} \
	-e 's|\(if (!stralloc_append(&firstpart,&ch)) temp_nomem();\)|if (ch == '"'\\\n'"' \&\& \!stralloc_append(\&firstpart,"\\r")) temp_nomem(); \1|' < ${EAI_PATCH}
PATCH_DIST_STRIP.${EAI_PATCH}=	-p1
.endif

PLIST_VARS+=			rejectutils
.if !empty(PKG_OPTIONS:Mqmail-rejectutils)
QMAILPATCHES+=			rejectutils:${REJECTUTILS_PATCH}
REJECTUTILS_PATCH=		netqmail-1.06-rejectutils-20170720.patch
PATCHFILES+=			${REJECTUTILS_PATCH}
SITES.${REJECTUTILS_PATCH}=	https://schmonz.com/qmail/rejectutils/
DJB_BUILD_TARGETS+=		rejectutils
PLIST.rejectutils=		yes
REJECTUTILS=			qmail-qfilter-ofmipd-queue	\
				qmail-qfilter-smtpd-queue	\
				qmail-qfilter-viruscan		\
				qmail-rcptcheck			\
				qmail-rcptcheck-badrcptto	\
				qmail-rcptcheck-qregex		\
				qmail-rcptcheck-realrcptto
.endif

PLIST_VARS+=			srs
.if !empty(PKG_OPTIONS:Mqmail-srs)
.  include "../../mail/libsrs2/buildlink3.mk"
QMAILPATCHES+=			srs:${SRS_PATCH}
SRS_PATCH=			qmail-srs-0.8.patch
PATCHFILES+=			${SRS_PATCH}
SITES.${SRS_PATCH}=		http://www.mco2.com.br/opensource/download/qmail/
PATCH_DIST_STRIP.${SRS_PATCH}=	-l
PATCH_DIST_CAT.${SRS_PATCH}=	${SED} -e 's|binm3 binm3+df|binm3 binm3+df update_tmprsadh|g' < ${SRS_PATCH}
SUBST_CLASSES+=			srsnetq1 srsnetq2
SUBST_STAGE.srsnetq1=		pre-patch
SUBST_STAGE.srsnetq2=		post-patch
SUBST_FILES.srsnetq1=		Makefile
SUBST_FILES.srsnetq2=		Makefile
SUBST_SED.srsnetq1=		-e 's|^auto_split.o env.a$$|auto_split.o|'
SUBST_SED.srsnetq2=		-e 's|^auto_split.o$$|auto_split.o env.a|'
SUBST_SED.srsnetq1+=		-e 's|^	substdio.a error.a str.a fs.a auto_qmail.o auto_split.o env.a$$|	substdio.a error.a str.a fs.a auto_qmail.o auto_split.o|'
SUBST_SED.srsnetq2+=		-e 's|^	substdio.a error.a str.a fs.a auto_qmail.o auto_split.o \\$$|	substdio.a error.a str.a fs.a auto_qmail.o auto_split.o env.a \\|'
SUBST_CLASSES+=			srsinclude
SUBST_STAGE.srsinclude=		do-configure
SUBST_FILES.srsinclude=		srs.c
SUBST_SED.srsinclude=		-e 's|/usr/local/include/srs2.h|srs2.h|'
SUBST_CLASSES+=			srsreadme
SUBST_STAGE.srsreadme=		do-configure
SUBST_FILES.srsreadme=		README.srs
SUBST_VARS.srsreadme=		PKG_SYSCONFDIR
PLIST.srs=			yes
MESSAGE_SRC+=			${PKGDIR}/MESSAGE.srs
READMES+=			README.srs
.endif

.if !empty(PKG_OPTIONS:Msyncdir)
.  include "../../devel/syncdir/buildlink3.mk"
SYNCDIR_DISTFILES_cmd=		( cd ../../devel/syncdir && ${MAKE} show-var VARNAME=DISTFILES )
QMAILPATCHES+=			syncdir:${SYNCDIR_DISTFILES_cmd:sh}
SUBST_CLASSES+=			load
SUBST_STAGE.load=		do-configure
SUBST_FILES.load=		make-load.sh
SUBST_SED.load=			-e '$$s|$$| ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.syncdir}/lib -L${BUILDLINK_PREFIX.syncdir}/lib \-lsyncdir|'
.  if ${OPSYS} == "Darwin"
SUBST_SED.load+=		-e '$$s|$$| -bind_at_load|'
.  endif
SUBST_MESSAGE.load=		Setting linker flags for syncdir.
.endif

PLIST_VARS+=			tls
.if !empty(PKG_OPTIONS:Msasl) || !empty(PKG_OPTIONS:Mtls)
.  if empty(PKG_OPTIONS:Msasl)
PKG_OPTIONS+=			sasl
.  endif
.  include "../../security/openssl/buildlink3.mk"
.  if !empty(PKG_OPTIONS:Mtls)
CFLAGS+=			-DTLS=20070408	# NOTE: match what's _in_ the patch
USE_TOOLS+=			openssl
SUBST_CLASSES+=			tmprsadh
SUBST_STAGE.tmprsadh=		do-configure
SUBST_FILES.tmprsadh=		update_tmprsadh.sh
SUBST_SED.tmprsadh=		-e 's|^export PATH=.*||'
SUBST_SED.tmprsadh+=		-e 's|^openssl |${OPENSSL} |'
PLIST.tls=			yes
.  endif
.else
BUILDLINK_TRANSFORM+=		rm:-lssl
BUILDLINK_TRANSFORM+=		rm:-lcrypto
.endif
