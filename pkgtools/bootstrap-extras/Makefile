# $NetBSD: Makefile,v 1.5 2008/04/12 22:43:09 jlam Exp $

DISTNAME=	bootstrap-extra-files-20070702
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extra bootstrap files and scripts for ${OPSYS}

NO_CHECKSUM=	yes
NO_MTREE=	yes
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
	${INSTALL_SCRIPT_DIR} ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/fakeldd ${PREFIX}/sbin/fakeldd

do-install-mkdir:
	${INSTALL_SCRIPT_DIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mkdir-sh ${PREFIX}/bin/mkdir-sh

do-install-strip:
	${INSTALL_SCRIPT_DIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/strip-sh ${PREFIX}/bin/strip

do-install-xargs:
	${INSTALL_SCRIPT_DIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/xargs-sh ${PREFIX}/bin/xargs

.include "../../mk/bsd.pkg.mk"
