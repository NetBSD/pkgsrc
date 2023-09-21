# $NetBSD: Makefile,v 1.40 2023/09/21 09:57:29 vins Exp $

DISTNAME=		racket-minimal-8.10-src
PKGNAME=		${DISTNAME:S/-src$//}
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES_PLT=	http://download.racket-lang.org/installers/${PKGVERSION_NOREV}/
MASTER_SITES_PLT+=	http://www.eecs.northwestern.edu/racket/${PKGVERSION_NOREV}/
MASTER_SITES_PLT+=	http://www.cs.utah.edu/plt/installers/${PKGVERSION_NOREV}/
MASTER_SITES_PLT+=	http://mirror.informatik.uni-tuebingen.de/mirror/racket/${PKGVERSION_NOREV}/
MASTER_SITES_PLT+=	ftp://infogroep.be/pub/racket/installers/${PKGVERSION_NOREV}/
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

PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
