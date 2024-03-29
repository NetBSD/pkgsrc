# $NetBSD: Makefile,v 1.41 2023/08/14 05:25:06 wiz Exp $

DISTNAME=	apsfilter-7.2.8
PKGREVISION=	3
CATEGORIES=	print
#MASTER_SITES=	http://www.apsfilter.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.apsfilter.org/
COMMENT=	Flexible magic filter for printing under Unix environment
LICENSE=	gnu-gpl-v2

DEPENDS+=	recode-[0-9]*:../../converters/recode
#DEPENDS+=	html2ps-[0-9]*:../../print/html2ps
DEPENDS+=	fig2dev-[0-9]*:../../print/fig2dev
DEPENDS+=	jpeg>=6b:../../graphics/jpeg
DEPENDS+=	netpbm>=9.7nb1:../../graphics/netpbm
DEPENDS+=	a2ps-[0-9]*:../../print/a2ps
DEPENDS+=	${PYPKGPREFIX}-pspdfutils-[0-9]*:../../print/py-pspdfutils

WRKSRC=		${WRKDIR}/apsfilter
HAS_CONFIGURE=	YES
USE_TOOLS+=	awk:run sh:run gs:run bzip2:run gzip:run file:run tar

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--with-shell=${SH:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--with-awk=${AWK:Q}

PKG_SYSCONFSUBDIR=	apsfilter
CONF_FILES=		${PREFIX}/share/apsfilter/template/apsfilterrc \
			${PKG_SYSCONFDIR}/apsfilterrc

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	bin/apsfilter.in SETUP.in tools/prtmgmt
SUBST_SED.prefix=	-e 's,/usr/local,${LOCALBASE},g'
SUBST_SED.prefix+=	-e 's,/usr/X11R6,${X11BASE},g'

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
