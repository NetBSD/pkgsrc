# $NetBSD: Makefile,v 1.2 2021/02/01 12:47:25 ryoon Exp $

DISTNAME=	got-0.48
CATEGORIES=	devel
MASTER_SITES=	https://gameoftrees.org/releases/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://gameoftrees.org/
COMMENT=	Game of Trees version control system manipulating Git repo
LICENSE=	isc

USE_TOOLS+=	awk find

INSTALLATION_DIRS=	bin libexec ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

MAKE_FLAGS+=	BINOWN=${BINOWN}
MAKE_FLAGS+=	BINGRP=${BINGRP}
MAKE_FLAGS+=	MANOWN=${MANOWN}
MAKE_FLAGS+=	MANGRP=${MANGRP}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	MKHTML=no

.include "../../mk/bsd.prefs.mk"

post-patch:
	${FIND} ${WRKSRC} -name '*.[cy]' -exec \
		${AWK} '/^#include /{c += 1;} \
			c == 1 { \
			gsub("(^#include )", "#include \"openbsd-compat.h\"\n&", $$0) \
			} \
			{print $$0 > "{}.back"} \
		' \
		{} \;
	${FIND} ${WRKSRC} -name '*.[cy]' -exec \
		cp {}.back {} \;
	${CP} -r ${FILESDIR}/openbsd-compat ${WRKSRC}/
.if ${OPSYS} == "NetBSD"
	# NetBSD has sha1.h.
	${RM} -f ${WRKSRC}/openbsd-compat/sha1.h
.endif

# For set_panel_userptr(3)'s second argument and waddwstr(3).
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
