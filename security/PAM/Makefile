# $NetBSD: Makefile,v 1.17 2003/10/18 12:40:11 cjep Exp $
#

DISTNAME=	Linux-${PKGNAME}
PKGNAME=	PAM-0.77
CATEGORIES=	security
MASTER_SITES=	http://www.kernel.org/pub/linux/libs/pam/pre/library/ \
		ftp://ftp.kernel.org/pub/linux/libs/pam/pre/library/ \
		http://www.de.kernel.org/pub/linux/libs/pam/pre/library/ \
		ftp://ftp.jp.kernel.org/pub/linux/libs/pam/pre/library/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.kernel.org/pub/linux/libs/pam/
COMMENT=	Pluggable Authentication Modules (PAM)

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
USE_GMAKE=		yes
USE_DB185=		yes

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

.include "../../mk/bsd.prefs.mk"

.if ${USE_LIBCRACK} == YES
.include "../../security/libcrack/buildlink2.mk"
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

CONF_FILES=		${EGDIR}/pam.conf ${PKG_SYSCONFBASE}/pam.conf
.for FILE in ${CFILES}
CONF_FILES+=		${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}
.endfor

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

.include "../../databases/db/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
