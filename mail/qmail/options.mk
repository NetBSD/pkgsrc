# $NetBSD: options.mk,v 1.69 2020/05/23 20:50:02 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.qmail
PKG_SUPPORTED_OPTIONS+=		eai inet6 pam syncdir tai-system-clock tls
PKG_SUPPORTED_OPTIONS+=		qmail-customerror qmail-srs
PKG_SUGGESTED_OPTIONS+=		eai syncdir tls
PKG_SUGGESTED_OPTIONS+=		qmail-customerror qmail-srs

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Meai)
.  include "../../devel/libidn2/buildlink3.mk"
QMAILPATCHES+=			eai:${EAI_PATCH}
EAI_PATCH=			netqmail-1.06-tls-20160918-onlyremote-20181107-spp-20181109-smtputf8-20181109.patch
PATCHFILES+=			${EAI_PATCH}
SITES.${EAI_PATCH}=		https://schmonz.com/qmail/eai/
CPPFLAGS+=			-DEHLO=1
.endif

.if !empty(PKG_OPTIONS:Mpam)
DEPENDS+=			checkpassword-pam>=0.99nb1:../../sysutils/checkpassword-pam
.else
DEPENDS+=			checkpassword>=0.90nb1:../../sysutils/checkpassword
.endif

.if !empty(PKG_OPTIONS:Mqmail-customerror)
QMAILPATCHES+=				customerror:${CUSTOMERROR_PATCH}
CUSTOMERROR_PATCH=			qmail-queue-custom-error-v2.netqmail-1.05.patch
PATCHFILES+=				${CUSTOMERROR_PATCH}
SITES.${CUSTOMERROR_PATCH}=		https://notes.sagredo.eu/files/qmail/patches/
PATCH_DIST_STRIP.${CUSTOMERROR_PATCH}=	-p1
PATCH_DIST_CAT.${CUSTOMERROR_PATCH}=	${SED} -e 's|vfork|fork|g' < ${CUSTOMERROR_PATCH}
.endif

PLIST_VARS+=			srs
.if !empty(PKG_OPTIONS:Mqmail-srs)
PLIST.srs=			yes
.  include "../../mail/libsrs2/buildlink3.mk"
QMAILPATCHES+=			srs:${SRS_PATCH}
SRS_PATCH=			notqmail-1.07-tls-20190517-qmailremote-20190819-srs-20190819.patch
PATCHFILES+=			${SRS_PATCH}
SITES.${SRS_PATCH}=		https://schmonz.com/qmail/srs/
PATCH_DIST_CAT.${SRS_PATCH}=	${SED} -e 's|compile forward.c sig.h readwrite.h exit.h env.h qmail.h substdio.h|compile forward.c sig.h readwrite.h env.h qmail.h substdio.h|g' < ${SRS_PATCH}
SUBST_CLASSES+=			srsinclude
SUBST_STAGE.srsinclude=		do-configure
SUBST_FILES.srsinclude=		srs.c
SUBST_SED.srsinclude=		-e 's|/usr/local/include/srs2.h|srs2.h|'
SUBST_CLASSES+=			srsreadme
SUBST_STAGE.srsreadme=		do-configure
SUBST_FILES.srsreadme=		README.srs
SUBST_VARS.srsreadme=		PKG_SYSCONFDIR
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

.if !empty(PKG_OPTIONS:Mtai-system-clock)
QMAILPATCHES+=				taileapsecs:${TAILEAPSECS_PATCH}
TAILEAPSECS_PATCH=			netqmail-1.05-TAI-leapsecs.patch
PATCHFILES+=				${TAILEAPSECS_PATCH}
SITES.${TAILEAPSECS_PATCH}=		https://su.bze.ro/software/
PATCH_DIST_STRIP.${TAILEAPSECS_PATCH}=	-p1
PATCH_DIST_CAT.${TAILEAPSECS_PATCH}=	\
				${SED} -e 's|"/etc/leapsecs.dat"|"@PKG_SYSCONFDIR@/leapsecs.dat"|' \
				-e 's|.*\./tryulong32.*| uid.o: \\\\|' \
				-e 's|.*cat uint32.*| compile uid.c uidgid.h subfd.h substdio.h exit.h|' \
				-e 's|.*rm -f tryulong32.*| 	./compile uid.c|' \
				< ${TAILEAPSECS_PATCH}
SUBST_CLASSES+=				libtai
SUBST_STAGE.libtai=			do-configure
SUBST_FILES.libtai=			leapsecs_read.c
SUBST_SED.libtai=			-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR.libtai}|g'
DEPENDS+=				libtai>=0.60nb5:../../devel/libtai
.endif

PLIST_VARS+=			tls
.if !empty(PKG_OPTIONS:Mtls)
PLIST.tls=			yes
.  include "../../security/openssl/buildlink3.mk"
CPPFLAGS+=			-DTLS=20200107	# NOTE: match what's _in_ the patch
USE_TOOLS+=			openssl
SUBST_CLASSES+=			tmprsadh
SUBST_STAGE.tmprsadh=		do-configure
SUBST_FILES.tmprsadh=		update_tmprsadh.sh
SUBST_SED.tmprsadh=		-e 's|^export PATH=.*||'
SUBST_SED.tmprsadh+=		-e 's|^openssl |${OPENSSL} |'
READMES+=			README.tls
SUBST_VARS.paths+=		OPENSSL QMAIL_DAEMON_USER QMAIL_QMAIL_GROUP
SUBST_VARS.paths+=		OPENSSL SERVERCERT CLIENTCERT
SUBST_SED.paths+=		-e 's|@SERVERCERT@|${PKG_SYSCONFDIR:Q}/control/servercert.pem|g'
SUBST_SED.paths+=		-e 's|@CLIENTCERT@|${PKG_SYSCONFDIR:Q}/control/clientcert.pem|g'
DEPENDS+=			ucspi-ssl>=0.999.10.11nb2:../../net/ucspi-ssl
.else
BUILDLINK_TRANSFORM+=		rm:-lssl
BUILDLINK_TRANSFORM+=		rm:-lcrypto
.  if !empty(PKG_OPTIONS:Minet6)
DEPENDS+=			ucspi-tcp6>=1.10.7nb1:../../net/ucspi-tcp6
.  else
DEPENDS+=			{ucspi-tcp6>=1.10.7nb1,ucspi-tcp-[0-9]*}:../../net/ucspi-tcp
.  endif
.endif
