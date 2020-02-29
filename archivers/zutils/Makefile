# $NetBSD: Makefile,v 1.12 2020/02/29 16:19:50 mef Exp $
#

DISTNAME=	zutils-1.8
CATEGORIES=	archivers
MASTER_SITES=	http://download.savannah.gnu.org/releases/zutils/
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/zutils/zutils.html
COMMENT=	Utilities for any combination of compressed and non-compressed files
LICENSE=	gnu-gpl-v3

CONFLICTS=		lzip<1.12

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc
USE_LANGUAGES=		c++
AUTO_MKDIRS=		yes

INFO_FILES=		yes
EGDIR=			${PREFIX}/share/examples/zutils
CONF_FILES=		${EGDIR}/zutilsrc ${PREFIX}/etc/zutilsrc

SUBST_CLASSES+=			sysconfdir
SUBST_STAGE.sysconfdir=		pre-configure
SUBST_FILES.sysconfdir=		zutilsrc
SUBST_MESSAGE.sysconfdir=	path of sysconfdir in example (zutilsrc)
SUBST_SED.sysconfdir=		-e '/sysconfdir/s,$${sysconfdir},${PREFIX}/etc,'

TEST_TARGET=	check

post-install:
	${MV}	${DESTDIR}${PREFIX}/etc/zutilsrc ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
