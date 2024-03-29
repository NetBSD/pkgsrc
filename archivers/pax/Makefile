# $NetBSD: Makefile,v 1.57 2022/11/09 13:14:07 joerg Exp $

DISTNAME=		pax-20210219
CATEGORIES=		archivers
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.NetBSD.org/
COMMENT=		POSIX standard archiver with many extensions
LICENSE=		2-clause-bsd AND modified-bsd AND public-domain

BOOTSTRAP_PKG=	yes
CHECK_PERMS=	no

MAKE_ENV+=		CATMAN_SECTION_SUFFIX=${CATMAN_SECTION_SUFFIX:Q}
MAKE_ENV+=		MANINSTALL=${MANINSTALL:Q}

USE_FEATURES=		nbcompat

CPPFLAGS.SunOS+=	-D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE=1

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
SUBST_CLASSES.Haiku+=	symlink
SUBST_STAGE.symlink=	pre-configure
SUBST_FILES.symlink=	Makefile.in
SUBST_SED.symlink=	-e 's,ln -f ,ln -sf ,g'

.include "../../mk/bsd.pkg.mk"
