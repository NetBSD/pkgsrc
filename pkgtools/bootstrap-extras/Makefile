# $NetBSD: Makefile,v 1.14 2025/04/21 15:58:55 wiz Exp $

PKGNAME=	bootstrap-extra-files-20250308
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extra bootstrap files and scripts for ${OPSYS}

POLICY_UPDATE_LIMITED=	bootstrap

BOOTSTRAP_PKG=	yes

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

EXTRA_FILES=	fakeldd mkdir strip
PLIST_VARS+=	${EXTRA_FILES}

.PHONY: ${EXTRA_FILES:S/^/do-install-/}

NEED_FAKELDD=		Haiku IRIX
.if !empty(NEED_FAKELDD:M${OPSYS})
PLIST.fakeldd=		yes
do-install:		do-install-fakeldd
.endif

NEED_MKDIR=		UnixWare
.if !empty(NEED_MKDIR:M${OPSYS})
PLIST.mkdir=		yes
do-install:		do-install-mkdir
.endif

NEED_STRIP=		AIX
.if !empty(NEED_STRIP:M${OPSYS})
PLIST.strip=		yes
do-install:		do-install-strip
.endif

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	@${ECHO} ${.ALLSRC}

do-install-fakeldd:
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PREFIX}/sbin
.if ${OPSYS} == "Haiku"
	${INSTALL_SCRIPT} ${WRKSRC}/fakeldd-${OPSYS} ${DESTDIR}${PREFIX}/sbin/fakeldd
.else
	${INSTALL_SCRIPT} ${WRKSRC}/fakeldd ${DESTDIR}${PREFIX}/sbin/fakeldd
.endif

do-install-mkdir:
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mkdir-sh ${DESTDIR}${PREFIX}/bin/mkdir-sh

do-install-strip:
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/strip-sh ${DESTDIR}${PREFIX}/bin/strip

.include "../../mk/bsd.pkg.mk"
