# $NetBSD: Makefile,v 1.28 2004/10/03 00:18:07 tv Exp $
#

DISTNAME=	Linux-PAM-0.77
PKGNAME=	${DISTNAME:S/Linux-//}
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.kernel.org/pub/linux/libs/pam/pre/library/ \
		ftp://ftp.kernel.org/pub/linux/libs/pam/pre/library/ \
		http://www.de.kernel.org/pub/linux/libs/pam/pre/library/ \
		ftp://ftp.jp.kernel.org/pub/linux/libs/pam/pre/library/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.kernel.org/pub/linux/libs/pam/
COMMENT=	Pluggable Authentication Modules (PAM)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_GNU_TOOLS+=		make

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-docdir=${PREFIX}/share/doc/PAM
CONFIGURE_ARGS+=	--enable-includedir=${PREFIX}/include
CONFIGURE_ARGS+=	--enable-mandir=${PREFIX}/man
CONFIGURE_ARGS+=	--enable-sconfigdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-static-libpam
CONFIGURE_ENV+=		ac_cv_prog_HAVE_SGML2TXT=no
CONFIGURE_ENV+=		ac_cv_prog_HAVE_SGML2HTML=no
CONFIGURE_ENV+=		ac_cv_prog_HAVE_SGML2LATEX=no
CONFIGURE_ENV+=		ac_cv_prog_HAVE_SGML2PS=no
CONFIGURE_ENV+=		ac_cv_prog_HAVE_PS2PDF=no

PAM_MODULEDIR=		${VIEWBASE}/lib/security
MAKE_ENV+=		PAM_MODULEDIR="${PAM_MODULEDIR}"
MESSAGE_SUBST+=		PAM_MODULEDIR=${PAM_MODULEDIR}

.include "../../mk/bsd.prefs.mk"

.if defined(USE_LIBCRACK) && !empty(USE_LIBCRACK:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	libcrack
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.PAM
PKG_SUPPORTED_OPTIONS=	libcrack
.include "../../mk/bsd.options.mk"

###
### Support using libcrack to protect against weak passwords.
###
.if !empty(PKG_OPTIONS:Mlibcrack)
.  include "../../security/libcrack/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libcrack
PLIST_SUBST+=		USE_LIBCRACK=
.else
CONFIGURE_ARGS+=	--without-libcrack
PLIST_SUBST+=		USE_LIBCRACK="@comment "
.endif

.if defined(LDCONFIG) && !exists(${LDCONFIG})
LDCONFIG=
.endif
MAKE_ENV+=	PKG_LDCONFIG=${LDCONFIG}

.if !empty(OPSYS:M*BSD)
CFLAGS+=		-DUSE_GETLOGIN=1
.endif
MAKE_FLAGS+=		OS_CFLAGS="${CFLAGS}"

PKG_SYSCONFSUBDIR?=	pam
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

CFILES=			access.conf pam_env.conf group.conf time.conf

.if ${OPSYS} == "Linux"
CFILES+=		limits.conf
PLIST_SUBST+=		PAM_LIMITS=
.else
PLIST_SUBST+=		PAM_LIMITS="@comment "
.endif

CONF_FILES=		${EGDIR}/pam.conf ${PKG_SYSCONFBASEDIR}/pam.conf
.for FILE in ${CFILES}
CONF_FILES+=		${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}
.endfor

.include "../../mk/bdb.buildlink3.mk"

post-configure:
	cd ${WRKSRC}; for file in libpam/pam_private.h; do		\
		${SED}	-e "s|/etc/|${PKG_SYSCONFBASEDIR}/|g"		\
			$$file > $$file.new;				\
		${MV} -f $$file.new $$file;				\
	done

# this is so it won't try to interactively install any configs
pre-build:
	${TOUCH} ${WRKSRC}/.quiet_install

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/pam.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/modules/pam_access/access.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/modules/pam_env/pam_env.conf-example	\
		${EGDIR}/pam_env.conf
	${INSTALL_DATA} ${WRKSRC}/modules/pam_group/group.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/modules/pam_time/time.conf ${EGDIR}
.if ${OPSYS} == "Linux"
	${INSTALL_DATA} ${WRKSRC}/security/modules/pam_limits/limits.skel \
		${EGDIR}/limits.conf
.endif
	${INSTALL_DATA_DIR} ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
