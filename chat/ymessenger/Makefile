# $NetBSD: Makefile,v 1.15 2006/05/02 14:13:11 gdt Exp $

DISTNAME=		ymessenger-1.0.4
CATEGORIES=		chat
MASTER_SITES=		http://download.yahoo.com/dl/unix/
DISTFILES=		rh9.${DISTNAME}-1.i386.rpm

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://messenger.yahoo.com/
COMMENT=		Yahoo! instant messaging client

RPMFILES=		${DISTFILES}

.include "../../emulators/suse_linux/Makefile.application"

EMULSUBDIR=		emul/linux

.if !defined(USE_NATIVE_LINUX)
DEPENDS+=		suse_compat>=6.4:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=		suse_gtk>=6.4:../../emulators/${SUSE_DIR_PREFIX}_gtk
DEPENDS+=		suse_gdk-pixbuf>=6.4:../../emulators/${SUSE_DIR_PREFIX}_gdk-pixbuf
.endif

ONLY_FOR_PLATFORM=	*-*-i386

CHECK_SHLIBS=		no

DIST_SUBDIR=		.

LICENSE=		generic-nonlicense
RESTRICTED=		Commercial software (no permission to copy is evident).
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC
PLIST_SUBST+=		EMULSUBDIR=${EMULSUBDIR:Q}

EMUL_YMESSENGER=	${PREFIX}/${EMULSUBDIR}/opt/ymessenger/bin/ymessenger
YMESSENGER=		${PREFIX}/bin/ymessenger
post-install:
	${SED} '1 s,bin,${EMULSUBDIR}/bin,' < ${EMUL_YMESSENGER} > ${YMESSENGER}
	${CHMOD} 755 ${YMESSENGER}

.include "../../mk/bsd.pkg.mk"
