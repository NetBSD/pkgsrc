# $NetBSD: Makefile,v 1.1 2020/11/29 13:23:40 he Exp $

PKGNAME=		libatomic-links-1.0
CATEGORIES=		devel

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Make libatomic available from a unique directory
LICENSE=		2-clause-bsd

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

.if (${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "powerpc")
# Only needed here so far; need stems from rust which wants -latomic
# but rust most probably should not always search /usr/pkg/lib
do-install:
	for f in $$(${PKG_INFO} -q -L libatomic); do \
		b=$$(basename $$f); \
		${LN} -s -f $$f ${DESTDIR}${PREFIX}/lib/libatomic/$$b; \
	done
.endif

.include "../../mk/bsd.pkg.mk"
