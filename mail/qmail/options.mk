# $NetBSD: options.mk,v 1.56 2018/11/08 20:58:08 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.qmail
PKG_SUPPORTED_OPTIONS+=		eai inet6 pam syncdir tls
PKG_SUPPORTED_OPTIONS+=		qmail-customerror qmail-srs
PKG_SUGGESTED_OPTIONS+=		eai syncdir tls
PKG_SUGGESTED_OPTIONS+=		qmail-customerror qmail-srs

# Formerly optional patches, now unconditionally applied:
QMAILPATCHES=			netqmail:${DEFAULT_DISTFILES}

QMAILPATCHES+=			tls:${TLSREMOTE_PATCH}
TLSREMOTE_PATCH=		netqmail-1.06-tls-20160918-onlyremote-20181107.patch
PATCHFILES+=			${TLSREMOTE_PATCH}
SITES.${TLSREMOTE_PATCH}=	https://schmonz.com/qmail/tlsonlyremote/

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

QMAILPATCHES+=			qbiffutmpx:${QBIFFUTMPX_PATCH}
QBIFFUTMPX_PATCH=		netqmail-1.06-qbiffutmpx-20170820.patch
PATCHFILES+=			${QBIFFUTMPX_PATCH}
SITES.${QBIFFUTMPX_PATCH}=	https://schmonz.com/qmail/qbiffutmpx/

QMAILPATCHES+=			rcptcheck:${RCPTCHECK_PATCH}
RCPTCHECK_PATCH=		qmail-smtpd.patch
PATCHFILES+=			${RCPTCHECK_PATCH}
SITES.${RCPTCHECK_PATCH}=	http://www.soffian.org/downloads/qmail/
PATCH_DIST_STRIP.${RCPTCHECK_PATCH}=-p1

QMAILPATCHES+=			remote:${REMOTE_PATCH}
REMOTE_PATCH=			netqmail-1.06-qmailremote-20170716.patch
PATCHFILES+=			${REMOTE_PATCH}
SITES.${REMOTE_PATCH}=		https://schmonz.com/qmail/remote/

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Meai)
.  include "../../devel/libidn2/buildlink3.mk"
QMAILPATCHES+=			eai:${EAI_PATCH}
EAI_PATCH=			netqmail-1.06-tls-20160918-onlyremote-20181107-smtputf8-20181107.patch
PATCHFILES+=			${EAI_PATCH}
SITES.${EAI_PATCH}=		https://schmonz.com/qmail/eai/
CFLAGS+=			-DEHLO=1
.endif

.if !empty(PKG_OPTIONS:Mpam)
DEPENDS+=			checkpassword-pam>=0.99nb1:../../sysutils/checkpassword-pam
.else
DEPENDS+=			checkpassword>=0.90nb1:../../sysutils/checkpassword
.endif

.if !empty(PKG_OPTIONS:Mqmail-customerror)
QMAILPATCHES+=			customerror:${CUSTOMERROR_PATCH}
CUSTOMERROR_PATCH=		qmail-queue-custom-error-v2.netqmail-1.05.patch
PATCHFILES+=			${CUSTOMERROR_PATCH}
SITES.${CUSTOMERROR_PATCH}=	https://notes.sagredo.eu/files/qmail/patches/
PATCH_DIST_STRIP.${CUSTOMERROR_PATCH}=-p1
.endif

PLIST_VARS+=			srs
.if !empty(PKG_OPTIONS:Mqmail-srs)
PLIST.srs=			yes
.  include "../../mail/libsrs2/buildlink3.mk"
QMAILPATCHES+=			srs:${SRS_PATCH}
SRS_PATCH=			qmail-srs-0.8.patch
PATCHFILES+=			${SRS_PATCH}
SITES.${SRS_PATCH}=		http://www.mco2.com.br/opensource/download/qmail/
PATCH_DIST_STRIP.${SRS_PATCH}=	-l
PATCH_DIST_CAT.${SRS_PATCH}=	${SED} -e 's|binm3 binm3+df|binm3 binm3+df update_tmprsadh|g' < ${SRS_PATCH}
SUBST_CLASSES+=			srsnetq1 srsnetq2
SUBST_STAGE.srsnetq1=		pre-patch
SUBST_STAGE.srsnetq2=		pre-configure
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
.if !empty(PKG_OPTIONS:Mtls)
PLIST.tls=			yes
.  include "../../security/openssl/buildlink3.mk"
CFLAGS+=			-DTLS=20160918	# NOTE: match what's _in_ the patch
USE_TOOLS+=			openssl
SUBST_CLASSES+=			tmprsadh
SUBST_STAGE.tmprsadh=		do-configure
SUBST_FILES.tmprsadh=		update_tmprsadh.sh
SUBST_SED.tmprsadh=		-e 's|^export PATH=.*||'
SUBST_SED.tmprsadh+=		-e 's|^openssl |${OPENSSL} |'
MESSAGE_SRC+=			${PKGDIR}/MESSAGE.tls
MESSAGE_SUBST+=			OPENSSL=${OPENSSL:Q}
MESSAGE_SUBST+=			SERVERCERT=${PKG_SYSCONFDIR:Q}/control/servercert.pem
MESSAGE_SUBST+=			CLIENTCERT=${PKG_SYSCONFDIR:Q}/control/clientcert.pem
MESSAGE_SUBST+=			QMAIL_DAEMON_USER=${QMAIL_DAEMON_USER:Q}
MESSAGE_SUBST+=			QMAIL_QMAIL_GROUP=${QMAIL_QMAIL_GROUP:Q}
DEPENDS+=			ucspi-ssl-[0-9]*:../../net/ucspi-ssl
.else
BUILDLINK_TRANSFORM+=		rm:-lssl
BUILDLINK_TRANSFORM+=		rm:-lcrypto
.if !empty(PKG_OPTIONS:Minet6)
DEPENDS+=			ucspi-tcp6-[0-9]*:../../net/ucspi-tcp6
.else
DEPENDS+=			ucspi-tcp-[0-9]*:../../net/ucspi-tcp
.endif
.endif
