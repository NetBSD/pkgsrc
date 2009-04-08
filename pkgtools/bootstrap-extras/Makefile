# $NetBSD: Makefile,v 1.8 2009/04/08 22:43:24 joerg Exp $

DISTNAME=	bootstrap-extra-files-20070702
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extra bootstrap files and scripts for ${OPSYS}

PKG_DESTDIR_SUPPORT=	user-destdir
BOOTSTRAP_PKG=	yes

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

EXTRA_FILES=	fakeldd mkdir strip xargs
PLIST_VARS+=	${EXTRA_FILES}

.PHONY: ${EXTRA_FILES:S/^/do-install-/}

NEED_FAKELDD=		IRIX
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

NEED_XARGS=		Interix
.if !empty(NEED_XARGS:M${OPSYS})
PLIST.xargs=		yes
do-install:		do-install-xargs
.endif

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	@${ECHO} ${.ALLSRC}

do-install-fakeldd:
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/fakeldd ${DESTDIR}${PREFIX}/sbin/fakeldd

do-install-mkdir:
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mkdir-sh ${DESTDIR}${PREFIX}/bin/mkdir-sh

do-install-strip:
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/strip-sh ${DESTDIR}${PREFIX}/bin/strip

do-install-xargs:
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/xargs-sh ${DESTDIR}${PREFIX}/bin/xargs

.include "../../mk/bsd.pkg.mk"
