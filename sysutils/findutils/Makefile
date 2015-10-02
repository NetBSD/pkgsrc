# $NetBSD: Makefile,v 1.34.2.1 2015/10/02 19:19:43 bsiegert Exp $

DISTNAME=	findutils-4.4.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=findutils/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/findutils/findutils.html
COMMENT=	The GNU find, locate, updatedb, and xargs utilities
LICENSE=	gnu-gpl-v3 # or later

GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake bison	# we patch a .y file, so needs bison

LDFLAGS.IRIX+=		-lgen

CONFIGURE_ARGS+=	--program-prefix=g

AUTO_MKDIRS=		yes

.include "../../mk/bsd.prefs.mk"

post-install:
.for f in find locate oldfind updatedb xargs
	${LN} -sf ${PREFIX}/bin/g${f} ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/${f}
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/g${f}.1 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/${f}.1
.endfor
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man5/glocatedb.5 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man5/locatedb.5

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
