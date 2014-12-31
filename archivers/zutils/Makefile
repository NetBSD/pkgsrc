# $NetBSD: Makefile,v 1.6 2014/12/31 01:25:22 mef Exp $
#

DISTNAME=	zutils-1.3
CATEGORIES=	archivers
MASTER_SITES=	http://download.savannah.gnu.org/releases/zutils/
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/zutils/zutils.html
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

SUBST_CLASSES+=		sysconfdir
SUBST_STAGE.sysconfdir=	post-patch
SUBST_FILES.sysconfdir= zutilsrc
SUBST_MESSAGE.sysconfdir= path of sysconfdir in example (zutilsrc)
SUBST_SED.sysconfdir=	-e '/sysconfdir/s,$${sysconfdir},${PREFIX}/etc,'

post-install:
	${MV}	${DESTDIR}${PREFIX}/etc/zutilsrc ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
