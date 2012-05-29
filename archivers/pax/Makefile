# $NetBSD: Makefile,v 1.46 2012/05/29 22:58:53 cheusov Exp $

DISTNAME=		pax-20080110
PKGREVISION=		1
CATEGORIES=		archivers
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		POSIX standard archiver with many extensions

PKG_DESTDIR_SUPPORT=	user-destdir
BOOTSTRAP_PKG=	yes
CHECK_PERMS=		no

MAKE_ENV+=		MANINSTALL=${MANINSTALL:Q}

USE_FEATURES=		nbcompat

.include "../../mk/bsd.prefs.mk"


.if defined(NBPAX_PROGRAM_PREFIX) && ${NBPAX_PROGRAM_PREFIX} != ""
CONFIGURE_ARGS+=	--program-prefix=${NBPAX_PROGRAM_PREFIX:Q}
.endif

PLIST_SUBST+=		NBPAX_PROGRAM_PREFIX=${NBPAX_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		NBPAX_PROGRAM_PREFIX

GNU_CONFIGURE=		yes

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

# Haiku (BeFS) cannot support hard link
.if ${OPSYS} == "Haiku"
SUBST_CLASSES+=		symlink
SUBST_STAGE.symlink=	pre-configure
SUBST_FILES.symlink=	Makefile.in
SUBST_SED.symlink=	-e 's,ln -f ,ln -sf ,g'
.endif

.include "../../mk/bsd.pkg.mk"
