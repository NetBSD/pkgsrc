# $NetBSD: Makefile,v 1.153 2022/01/24 22:39:29 wiz Exp $
#
# ATTENTION:
# The Kerberos support in this software is known to be problematic. If you
# upgrade this package you *must* test it on a system with Kerberos libraries
# but not running Kerberos before committing the changes.
#
# NOTE ALSO:
# The most common reason to install this package is as a prerequisite for pine.
# If you upgrade this package, you *must* test mail/pine with the new version.

DISTNAME=	imap-2007f
PKGNAME=	${DISTNAME:S/-/-uw-/}
PKGREVISION=	11
CATEGORIES=	mail
#MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.washington.edu/imap/
COMMENT=	University of Washington's IMAP, POP2, and POP3 servers
LICENSE=	apache-2.0

USE_LIBTOOL=		yes
MAKE_ENV+=		LIBTOOL=libtool
MAKE_ENV+=		LTCOMPILE="libtool --tag=CC --mode=compile"
MAKE_ENV+=		LTLINK="libtool --tag=CC --mode=link"
LTINSTALL_PROGRAM=	${SETENV} ${MAKE_ENV} ${LIBTOOL} --tag=CC --mode=install ${INSTALL_PROGRAM}
LTINSTALL_LIB=		${SETENV} ${MAKE_ENV} ${LIBTOOL} --tag=CC --mode=install ${INSTALL_LIB}

WRKSRC=		${WRKDIR}/${DISTNAME:S/2$//}

MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.prefs.mk"

.include "../../mk/compiler.mk"
.  if empty(CC_VERSION:Mgcc-)
BUILD_TARGET.SunOS=	soc
.  else
BUILD_TARGET.SunOS=	gso
.  endif
.if ${OPSYS} == Linux && exists(/usr/include/security/pam_appl.h)
BUILD_TARGET.Linux=	lnp
.else
BUILD_TARGET.Linux=	slx
.endif
.if ${OPSYS} == Darwin
LDFLAGS+=		-flat_namespace
.   if exists(/usr/include/pam/pam_appl.h)
BUILD_TARGET.Darwin=	oxp
.   else
BUILD_TARGET.Darwin=	osx
.   endif
.endif
.if ${OPSYS} == "IRIX"
.  if ${OPSYS_VERSION} >= 060500
BUILD_TARGET.IRIX=	sg6
.  else
BUILD_TARGET.IRIX=	sgi
.  endif
.endif
BUILD_TARGET.OSF1=	osf
BUILD_TARGET.OpenBSD=	bso
BUILD_TARGET.*=		neb
.if ${OS_VARIANT} == "SCOOSR5"
BUILD_TARGET.SCO_SV=	sc5
.endif
MESSAGE_SRC=		${PKGDIR}/MESSAGE

# XXX this is not the right approach - should either depend on pam or
# not, or make it an option.
.if ${OPSYS} == NetBSD && !exists(/usr/include/security/pam_appl.h)
.include "../../mk/pam.buildlink3.mk"
.endif

.include "options.mk"

# The defaults for these values are set in pkgsrc/mk/defaults/mk.conf.
#IMAP_UW_CCLIENT_MBOX_FMT?=	unix
#IMAP_UW_MAILSPOOLHOME?=	.Mailbox
BUILD_DEFS+=			IMAP_UW_CCLIENT_MBOX_FMT IMAP_UW_MAILSPOOLHOME

CCLIENT_LIB=		libc-client.la
CCLIENT_PICLIB=		libc-client_pic.a
CCLIENT_MAJOR=		5
CCLIENT_MINOR=		0
MAKE_ENV+=		CCLIENT_MAJOR=${CCLIENT_MAJOR:Q}
MAKE_ENV+=		CCLIENT_MINOR=${CCLIENT_MINOR:Q}

EXTRASPECIALS+=		CREATEPROTO=${IMAP_UW_CCLIENT_MBOX_FMT:Q}proto

MAKE_FLAGS+=		EXTRALDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=		EXTRACFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=		EXTRASPECIALS=${EXTRASPECIALS:Q}

SUBST_CLASSES+=		mbox
SUBST_STAGE.mbox=	do-configure
SUBST_FILES.mbox=	src/osdep/unix/env_unix.c
.if defined(IMAP_USE_MAILSPOOLHOME)
SUBST_SED.mbox=		-e 's|@SPOOLDIR@|myhomedir ()|'
SUBST_SED.mbox+=	-e 's|@MAILBOX@|"${IMAP_UW_MAILSPOOLHOME}"|'
.else
SUBST_SED.mbox=		-e 's|@SPOOLDIR@|MAILSPOOL|'
SUBST_SED.mbox+=	-e 's|@MAILBOX@|myusername ()|'
.endif

SUBST_CLASSES+=		man
SUBST_STAGE.man=	post-build
SUBST_FILES.man=	src/imapd/imapd.8 src/ipopd/ipopd.8
SUBST_SED.man=		-e "s|/usr/etc/imapd|${PREFIX}/libexec/imapd|g"
SUBST_SED.man+=		-e "s|/etc/rimapd|${PREFIX}/sbin/rimapd|g"
SUBST_SED.man+=		-e "s|/usr/etc/ipop2d|${PREFIX}/libexec/ipop2d|g"
SUBST_SED.man+=		-e "s|/usr/etc/ipop3d|${PREFIX}/libexec/ipop3d|g"

INSTALLATION_DIRS+=	bin lib libexec sbin				\
			${PKGMANDIR}/man1 ${PKGMANDIR}/man8

# Generate _pic.a library from shared objects.
post-build:
	cd ${WRKSRC}/c-client;						\
	${LIBTOOL} --mode=link ${CC} -o ${CCLIENT_PICLIB:.a=.la} *.lo

do-install: install-headers install-lib install-doc
	${LTINSTALL_PROGRAM} ${WRKSRC}/imapd/imapd ${DESTDIR}${PREFIX}/libexec
	${LTINSTALL_PROGRAM} ${WRKSRC}/ipopd/ipop2d ${DESTDIR}${PREFIX}/libexec
	${LTINSTALL_PROGRAM} ${WRKSRC}/ipopd/ipop3d ${DESTDIR}${PREFIX}/libexec
	${LTINSTALL_PROGRAM} ${WRKSRC}/mtest/mtest ${DESTDIR}${PREFIX}/sbin
	${LN} -sf ../libexec/imapd ${DESTDIR}${PREFIX}/sbin/rimapd
	${INSTALL_MAN} ${WRKSRC}/src/imapd/imapd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/src/ipopd/ipopd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${LN} -sf ipopd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/ipop2d.8
	${LN} -sf ipopd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/ipop3d.8
	${LTINSTALL_PROGRAM} ${WRKSRC}/mailutil/mailutil ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src/mailutil/mailutil.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${LTINSTALL_PROGRAM} ${WRKSRC}/dmail/dmail ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src/dmail/dmail.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${LTINSTALL_PROGRAM} ${WRKSRC}/mlock/mlock ${DESTDIR}${PREFIX}/bin
	${LTINSTALL_PROGRAM} ${WRKSRC}/tmail/tmail ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src/tmail/tmail.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.PHONY: install-headers install-lib install-doc
install-headers:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/c-client
	${CAT} ${PKGDIR}/PLIST |					\
	while read entry; do						\
		case "$$entry" in					\
		include/c-client/*)					\
			src="${WRKSRC}/c-client/`${BASENAME} $$entry`";	\
			dest="${DESTDIR}${PREFIX}/$$entry";		\
			${INSTALL_DATA} $$src $$dest;			\
		esac;							\
	done

install-lib:
	${LTINSTALL_LIB} ${WRKSRC}/c-client/${CCLIENT_LIB} ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/c-client/.libs/${CCLIENT_PICLIB} ${DESTDIR}${PREFIX}/lib
	${RANLIB} ${DESTDIR}${PREFIX}/lib/${CCLIENT_PICLIB}

DOCDIR=	${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
install-doc:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${CP} -R ${WRKSRC}/docs/* ${DOCDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCDIR}
	${FIND} ${DOCDIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DOCDIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../devel/sysexits/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
