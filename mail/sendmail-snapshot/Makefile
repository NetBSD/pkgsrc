# $NetBSD: Makefile,v 1.2 2024/05/05 21:01:04 wiz Exp $

PKGNAME=	sendmail-${DIST_VERS}
PKGREVISION=	1
COMMENT=	The well known Mail Transport Agent

CONFLICTS+=	courier-mta-[0-9]* fastforward>=0.51nb2 postfix-[0-9]*
CONFLICTS+=	esmtp>=1.2

.include "options.mk"
.include "../../mail/sendmail-snapshot/Makefile.common"

USE_TOOLS+=	pax

MESSAGE_SRC=	${WRKDIR}/.MESSAGE_SRC
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

SMRSH_CMDDIR?=	${PREFIX}/libexec/sm.bin
PLIST_SUBST+=	SMRSH_CMDDIR=${SMRSH_CMDDIR}
RCD_SCRIPTS=	sendmail smmsp
SMF_METHODS=	sendmail sendmail_include smmsp

BUILD_DEFS+=	VARBASE

# Not OWN_DIRS, so that the admin doesn't get a suggestion to delete the
# queue dirs if they are nonempty at deinstall (probably undesirable).
#
MAKE_DIRS_PERMS+=	/${VARBASE}/spool/clientmqueue smmsp smmsp 0770
MAKE_DIRS_PERMS+=	/${VARBASE}/spool/mqueue ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700

SPECIAL_PERMS+=		libexec/sendmail/sendmail ${REAL_ROOT_USER} smmsp 2555
SPECIAL_PERMS+=		libexec/sendmail/mail.local ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 4555

PKG_GROUPS=		smmsp
PKG_USERS=		smmsp:smmsp
PKG_GECOS.smmsp=	Sendmail Message Submission Program

SUBST_CLASSES+=		paths
SUBST_CLASSES+=		cf-paths

SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	../mailer.conf smrsh/smrsh.8 cf/cf/Makefile
SUBST_SED.paths+=	-e "s|@@BINGRP@@|${BINGRP}|g"
SUBST_SED.paths+=	-e "s|@@BINOWN@@|${BINOWN}|g"
SUBST_SED.paths+=	-e "s|@@INSTALL@@|${INSTALL}|g"
SUBST_SED.paths+=	-e "s|@@PREFIX@@|${PREFIX}|g"
SUBST_SED.paths+=	-e "s|@@SMRSH_CMDDIR@@|${SMRSH_CMDDIR}|g"
SUBST_MESSAGE.paths=	Fixing paths.

SUBST_STAGE.cf-paths=	pre-build
.for f in cf/README cf/cf/generic-bsd4.4.cf cf/cf/generic-hpux10.cf	\
	cf/cf/generic-hpux9.cf cf/cf/generic-linux.cf			\
	cf/cf/generic-mpeix.cf cf/cf/generic-nextstep3.3.cf		\
	cf/cf/generic-osf1.cf cf/cf/generic-solaris.cf			\
	cf/cf/generic-sunos4.1.cf cf/cf/generic-ultrix4.cf		\
	cf/cf/knecht.mc cf/cf/submit.cf cf/feature/local_lmtp.m4	\
	cf/feature/msp.m4 cf/feature/smrsh.m4 cf/m4/proto.m4		\
	cf/mailer/pop.m4 cf/mailer/usenet.m4 cf/ostype/a-ux.m4		\
	cf/ostype/aix3.m4 cf/ostype/aix4.m4 cf/ostype/aix5.m4		\
	cf/ostype/altos.m4 cf/ostype/amdahl-uts.m4 cf/ostype/bsd4.4.m4	\
	cf/ostype/darwin.m4 cf/ostype/dgux.m4 cf/ostype/domainos.m4	\
	cf/ostype/dragonfly.m4 cf/ostype/dynix3.2.m4			\
	cf/ostype/freebsd4.m4 cf/ostype/freebsd5.m4			\
	cf/ostype/freebsd6.m4 cf/ostype/hpux10.m4 cf/ostype/hpux9.m4	\
	cf/ostype/irix4.m4 cf/ostype/irix5.m4 cf/ostype/irix6.m4	\
	cf/ostype/isc4.1.m4 cf/ostype/maxion.m4 cf/ostype/nextstep.m4	\
	cf/ostype/openbsd.m4 cf/ostype/ptx2.m4 cf/ostype/riscos4.5.m4	\
	cf/ostype/sco-uw-2.1.m4 cf/ostype/sco3.2.m4 cf/ostype/sinix.m4	\
	cf/ostype/solaris11.m4 cf/ostype/solaris2.m4			\
	cf/ostype/solaris2.ml.m4 cf/ostype/solaris2.pre5.m4		\
	cf/ostype/solaris8.m4 cf/ostype/sunos3.5.m4			\
	cf/ostype/sunos4.1.m4 cf/ostype/ultrix4.m4 cf/ostype/unicos.m4	\
	cf/ostype/unicosmk.m4 cf/ostype/unicosmp.m4			\
	cf/ostype/unixware7.m4
SUBST_FILES.cf-paths+=	${f}
.endfor
SUBST_SED.cf-paths+=	-e "s|/var/spool|${VARBASE}/spool|g"
SUBST_SED.cf-paths+=	-e "s|/var/run|${VARBASE}/run|g"
SUBST_SED.cf-paths+=	-e "s|/usr/libexec|${PREFIX}/libexec/sendmail|g"
SUBST_SED.cf-paths+=	-e "s|/usr/lib|${PREFIX}/libexec/sendmail|g"
SUBST_NOOP_OK.cf-paths=	yes # some files contain only /var

REPLACE_PERL=		contrib/socketmapClient.pl contrib/socketmapServer.pl

AUTO_MKDIRS=	yes

post-patch: make-sendmail-siteconfig
.if !empty(PKG_OPTIONS:Mtcpwrappers)
	cat ${FILESDIR}/site.config.m4-tcpwrappers >>${SITECONFIG}
.endif
.if !empty(PKG_OPTIONS:Mldap)
	cat ${FILESDIR}/site.config.m4-ldap >>${SITECONFIG}
.endif
.if !empty(PKG_OPTIONS:Mdb2)
	cat ${FILESDIR}/site.config.m4-db2 >>${SITECONFIG}
.endif
.if !empty(PKG_OPTIONS:Mdb4)
	cat ${FILESDIR}/site.config.m4-db4 >>${SITECONFIG}
.endif
.if !empty(PKG_OPTIONS:Mtls)
	cat ${FILESDIR}/site.config.m4-starttls >>${SITECONFIG}
.endif
.if !empty(PKG_OPTIONS:Msendmail-ffr-tls)
	cat ${FILESDIR}/site.config.m4-ffr_tls >>${SITECONFIG}
.endif
.if !empty(PKG_OPTIONS:Msasl)
	cat ${FILESDIR}/site.config.m4-sasl2 >>${SITECONFIG}
.endif
.if !empty(PKG_OPTIONS:Msendmail-ffr-badrcptshutdown)
	cat ${FILESDIR}/site.config.m4-ffr_badrcptshutdown >>${SITECONFIG}
.endif
.if !empty(PKG_OPTIONS:Mblacklist)
	cat ${FILESDIR}/site.config.m4-blacklistd >>${SITECONFIG}
.endif
.if !empty(PKG_OPTIONS:Msmtputf8)
	cat ${FILESDIR}/site.config.m4-smtputf8 >>${SITECONFIG}
.endif

post-extract:
	cp ${FILESDIR}/mailer.conf ${WRKDIR}/mailer.conf

do-build:
	(cd ${WRKSRC} && env ${MAKE_ENV} ./Build)
	(cd ${WRKSRC}/cf/cf && env ${MAKE_ENV} ./Build)

post-build:
	cp ${PKGDIR}/MESSAGE ${MESSAGE_SRC}
	cp ${PKGDIR}/PLIST ${WRKDIR}/.PLIST_SRC

post-install:
	(cd ${WRKSRC}/mail.local && env ${INSTALL_ENV} ${MAKE_ENV} ./Build force-install)

	${INSTALL_DATA} ${WRKDIR}/mailer.conf \
		${DESTDIR}${PREFIX}/share/examples/sendmail/
	cd ${WRKSRC}/cf && pax -rw -pp -pm -s',^.*\.orig$$,,' . ${DESTDIR}${PREFIX}/share/sendmail
	cp ${FILESDIR}/netbsd-proto.mc ${DESTDIR}${PREFIX}/share/sendmail/cf

	${INSTALL_DATA} ${WRKSRC}/obj.`${UNAME} -srm | tr \  . | tr \/ - | sed s/sun4./sun4/`/libsm/libsm.a \
		${DESTDIR}${PREFIX}/lib

	${INSTALL_DATA} \
		${WRKSRC}/obj.`${UNAME} -srm | tr \  . | tr \/ - | sed s/sun4./sun4/`/libsmutil/libsmutil.a \
		${DESTDIR}${PREFIX}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/socketmap*.pl \
		${DESTDIR}${PREFIX}/share/examples/sendmail/
	${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES ${DESTDIR}${PREFIX}/share/doc/sendmail
	${INSTALL_DATA} ${WRKSRC}/cf/README ${DESTDIR}${PREFIX}/share/doc/sendmail
	${INSTALL_DATA} ${WRKSRC}/sendmail/SECURITY ${DESTDIR}${PREFIX}/share/doc/sendmail
	${INSTALL_DATA} ${WRKSRC}/doc/op/op.me ${DESTDIR}${PREFIX}/share/doc/sendmail
	${INSTALL_DATA} ${WRKSRC}/doc/op/op.ps ${DESTDIR}${PREFIX}/share/doc/sendmail

.include "../../mk/bsd.pkg.mk"

# has to be below include for bsd.pkg.mk, else substition fails
OBJDIR!=	${ECHO} obj.`${UNAME} -srm | tr \  . | tr \/ -`
