# $NetBSD: Makefile,v 1.33 2012/12/16 18:13:28 wiz Exp $

DISTNAME=	findutils-4.2.33
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=findutils/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/findutils/findutils.html
COMMENT=	The GNU find, locate, updatedb, and xargs utilities
LICENSE=	gnu-gpl-v3 # or later

GNU_CONFIGURE=		YES
INFO_FILES=		YES
USE_PKGLOCALEDIR=	YES

LDFLAGS.IRIX+=		-lgen

CONFIGURE_ARGS+=	--program-prefix=g

AUTO_MKDIRS=		yes

.include "../../mk/bsd.prefs.mk"

post-install:
.for f in find locate updatedb xargs
	${LN} -sf ${PREFIX}/bin/g${f} ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/${f}
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/g${f}.1 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/${f}.1
.endfor
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man5/glocatedb.5 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man5/locatedb.5

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
