# $NetBSD: Makefile,v 1.3 2021/01/03 18:28:05 he Exp $

PKGNAME=		libatomic-links-1.0
CATEGORIES=		devel

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Make libatomic available from a unique directory
LICENSE=		2-clause-bsd

ONLY_FOR_PLATFORM+=	NetBSD-*-powerpc
ONLY_FOR_PLATFORM+=	NetBSD-*-i386

DEPENDS+=		libatomic-[0-9]*:../../devel/libatomic

GENERATE_PLIST=		cd ${DESTDIR}${PREFIX}; \
			${FIND} lib/libatomic -type l | ${SORT};

# Almost a meta package...
PKG_DESTDIR_SUPPORT=	user-destdir
NO_CONFIGURE=		yes
NO_BUILD=		yes
DISTFILES=		# none
PLIST_SRC=		# none
CHECK_PERMS=		no
USE_LANGUAGES=		# empty
WRKSRC=			${WRKDIR}

INSTALLATION_DIRS+=	lib/libatomic

.include "../../mk/bsd.prefs.mk"

do-patch:
	@${DO_NADA}

# Only needed here so far; need stems from rust which wants -latomic
# but rust most probably should not always search /usr/pkg/lib
do-install:
	for f in $$(${PKG_INFO} -q -L libatomic); do \
		b=$$(basename $$f); \
		${LN} -s -f $$f ${DESTDIR}${PREFIX}/lib/libatomic/$$b; \
	done

.include "../../mk/bsd.pkg.mk"
