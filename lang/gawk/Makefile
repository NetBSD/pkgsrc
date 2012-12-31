# $NetBSD: Makefile,v 1.53 2012/12/31 00:27:36 sbd Exp $

DISTNAME=	gawk-4.0.1
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gawk/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gawk/gawk.html
COMMENT=	GNU awk
LICENSE=	gnu-gpl-v3

CONFLICTS=	ja-gawk-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
TEST_TARGET=		check
INFO_FILES=		yes

MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}

LDFLAGS.IRIX+=		-lgen
CPPFLAGS.OSF1+=		-D_OSF_SOURCE

.include "../../mk/bsd.prefs.mk"

.include "options.mk"

.if !empty(MACHINE_PLATFORM:MDarwin-*-x86_64)
CFLAGS+=	-Dvm_region=vm_region_64
.endif

INSTALLATION_DIRS+=	${PKGGNUDIR}bin ${PKGGNUDIR}${PKGMANDIR}/man1

post-install:
	${LN} -s ${PREFIX}/bin/gawk ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/awk
	${LN} -s ${PREFIX}/${PKGMANDIR}/man1/gawk.1 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/awk.1

BUILDLINK_API_DEPENDS.gettext+=	gettext-lib>=0.10.36

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
