# $NetBSD: Makefile,v 1.44 2024/03/04 15:38:33 riastradh Exp $

DISTNAME=		racket-minimal-8.11.1-src
PKGNAME=		${DISTNAME:S/-src$//}
CATEGORIES=		lang
MASTER_SITES_PLT=	https://mirror.racket-lang.org/installers/${PKGVERSION_NOREV}/
MASTER_SITES_PLT+=	https://www-old.cs.utah.edu/plt/installers/${PKGVERSION_NOREV}/
# Pre-release:
#MASTER_SITES_PLT=	http://pre-release.racket-lang.org/installers/
MASTER_SITES=		${MASTER_SITES_PLT}
EXTRACT_SUFX=		.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://racket-lang.org/
COMMENT=	Scheme-based dialect of Lisp
LICENSE=	gnu-lgpl-v2

CONFLICTS+=	drscheme-[0-9]* mzscheme-[0-9]* racket-[0-9]*

PATCHDIR=	${.CURDIR}/../../lang/racket/patches

WRKSRC=		${WRKDIR}/racket-${PKGVERSION_NOREV}

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		src
CONFIGURE_ARGS=		--enable-pthread
CONFIGURE_ARGS+=	--enable-curses
CONFIGURE_ARGS+=	--enable-iconv

# On macOS, Racket insists that we choose between Unix-style or
# Mac-style installation:
#
# ERROR: --prefix not allowed for a Mac OS build, unless either
#          --enable-xonx is supplied (to create a Unix-style
#            build), or 
#          --enable-macprefix is supplied (to allow a Mac-style
#            installation, even though --prefix is normally used
#            for Unix-style installations)
CONFIGURE_ARGS.Darwin+=	--enable-xonx

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config gmake
USE_TOOLS.NetBSD+=	paxctl
MAKE_JOBS_SAFE=		no
UNLIMIT_RESOURCES=	datasize
OVERRIDE_DIRDEPTH=	3
CONFIGURE_ENV.NetBSD+=	PAXCTL=${TOOLS_PLATFORM.paxctl:Q}
PLIST_SUBST+=		PREFIX=${PREFIX:Q}

CPPFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS
LDFLAGS.DragonFly+=	-rdynamic

# REPLACE_INTERPRETER+=	racket
# REPLACE.racket.old=	.*racket
# REPLACE.racket.new=	${PREFIX}/bin/racket
# REPLACE_FILES.racket=	${REPLACE_RACKET}

EGDIR=			share/examples/racket
INSTALLATION_DIRS+=	${EGDIR}
OWN_DIRS+=		${PKG_SYSCONFDIR}/racket
CONF_FILES+=		${EGDIR}/config.rktd \
			${PKG_SYSCONFDIR}/racket/config.rktd

post-install:
	${MV} -f ${DESTDIR:Q}${PKG_SYSCONFDIR:Q}/racket/config.rktd \
		${DESTDIR:Q}${PREFIX:Q}/${EGDIR:Q}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"

PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
