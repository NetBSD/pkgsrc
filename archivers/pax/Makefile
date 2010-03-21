# $NetBSD: Makefile,v 1.41 2010/03/21 16:29:38 wiz Exp $

DISTNAME=		pax-20080110
CATEGORIES=		archivers
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		POSIX standard archiver with many extensions

PKG_DESTDIR_SUPPORT=	user-destdir
BOOTSTRAP_PKG=	yes
CHECK_PERMS=		no

USE_FEATURES=		nbcompat

.include "../../mk/bsd.prefs.mk"


.if defined(NBPAX_PROGRAM_PREFIX) && ${NBPAX_PROGRAM_PREFIX} != ""
CONFIGURE_ARGS+=	--program-prefix=${NBPAX_PROGRAM_PREFIX:Q}

.else

# pax installs "tar" and "cpio"
.if defined(GNU_PROGRAM_PREFIX) && empty(GNU_PROGRAM_PREFIX)
CONFLICTS+=		gcpio-[0-9]*
.endif
.if defined(GTAR_PROGRAM_PREFIX) && empty(GTAR_PROGRAM_PREFIX)
CONFLICTS+=		gtar-base-[0-9]*
.endif

.endif

PLIST_SUBST+=		NBPAX_PROGRAM_PREFIX=${NBPAX_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		NBPAX_PROGRAM_PREFIX

GNU_CONFIGURE=		yes

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
