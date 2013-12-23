# $NetBSD: Makefile,v 1.50 2013/12/23 11:57:05 wiz Exp $

DISTNAME=	Linux-PAM-0.77
PKGNAME=	${DISTNAME:S/Linux-//}
PKGREVISION=	6
CATEGORIES=	security
MASTER_SITES=	http://www.kernel.org/pub/linux/libs/pam/pre/library/ \
		ftp://ftp.kernel.org/pub/linux/libs/pam/pre/library/ \
		http://www.de.kernel.org/pub/linux/libs/pam/pre/library/ \
		ftp://ftp.jp.kernel.org/pub/linux/libs/pam/pre/library/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kernel.org/pub/linux/libs/pam/
COMMENT=	Pluggable Authentication Modules (PAM)

MAKE_JOBS_SAFE=	no

CONFLICTS+=	openpam-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-docdir=${PREFIX}/share/doc/PAM
CONFIGURE_ARGS+=	--enable-includedir=${PREFIX}/include
CONFIGURE_ARGS+=	--enable-mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--enable-sconfigdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-static-libpam
CONFIGURE_ENV+=		ac_cv_prog_HAVE_SGML2TXT=no
CONFIGURE_ENV+=		ac_cv_prog_HAVE_SGML2HTML=no
CONFIGURE_ENV+=		ac_cv_prog_HAVE_SGML2LATEX=no
CONFIGURE_ENV+=		ac_cv_prog_HAVE_SGML2PS=no
CONFIGURE_ENV+=		ac_cv_prog_HAVE_PS2PDF=no

MAKE_FLAGS+=		CC=cc
INSTALL_MAKE_FLAGS+=	FAKEROOT=${DESTDIR}

PAM_MODULEDIR=		${VIEWBASE}/lib/security
MAKE_ENV+=		PAM_MODULEDIR=${PAM_MODULEDIR:Q}
MESSAGE_SUBST+=		PAM_MODULEDIR=${PAM_MODULEDIR}

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.PAM
PKG_SUPPORTED_OPTIONS=	libcrack

.include "../../mk/bsd.options.mk"

###
### Support using libcrack to protect against weak passwords.
###
PLIST_VARS+=		libcrack
.if !empty(PKG_OPTIONS:Mlibcrack)
.  include "../../security/libcrack/buildlink3.mk"
PLIST.libcrack=		yes
.else
CONFIGURE_ARGS+=	--disable-crack
.endif

.if !empty(OPSYS:M*BSD)
CPPFLAGS+=		-DUSE_GETLOGIN=1
.endif

# pam_userdb uses ndbm if it finds it, otherwise it will use Berkeley DB.
.if !exists(/usr/include/ndbm.h)
.  include "../../mk/bdb.buildlink3.mk"
.endif

PKG_SYSCONFSUBDIR?=	pam
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

CFILES=			access.conf pam_env.conf group.conf time.conf

PLIST_VARS+=		limits
.if ${OPSYS} == "Linux"
CFILES+=		limits.conf
PLIST.limits=		yes
.endif

CONF_FILES=		${EGDIR}/pam.conf ${PKG_SYSCONFBASEDIR}/pam.conf
.for file in ${CFILES}
CONF_FILES+=		${EGDIR}/${file} ${PKG_SYSCONFDIR}/${file}
.endfor
SPECIAL_PERMS=		${PREFIX}/sbin/unix_chkpwd ${SETUID_ROOT_PERMS}

post-configure:
	cd ${WRKSRC}; for file in Make.Rules; do			\
		${SED}	-e "s|@LIBTOOL@|${LIBTOOL}|g"			\
			-e "s|@SHLIBTOOL@|${SHLIBTOOL}|g"		\
			$$file > $$file.new;				\
		${MV} -f $$file.new $$file;				\
	done
	cd ${WRKSRC}; for file in libpam/pam_private.h; do		\
		${SED}	-e "s|/etc/|${PKG_SYSCONFBASEDIR}/|g"		\
			$$file > $$file.new;				\
		${MV} -f $$file.new $$file;				\
	done

# this is so it won't try to interactively install any configs
pre-build:
	${TOUCH} ${WRKSRC}/.quiet_install

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/pam.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/modules/pam_access/access.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/modules/pam_env/pam_env.conf-example	\
		${DESTDIR}${EGDIR}/pam_env.conf
	${INSTALL_DATA} ${WRKSRC}/modules/pam_group/group.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/modules/pam_time/time.conf ${DESTDIR}${EGDIR}
.if ${OPSYS} == "Linux"
	${INSTALL_DATA} ${WRKSRC}/security/modules/pam_limits/limits.skel \
		${DESTDIR}${EGDIR}/limits.conf
.endif

.include "../../mk/bsd.pkg.mk"
