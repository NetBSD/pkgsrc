# $NetBSD: Makefile,v 1.2 2020/05/12 12:12:25 jperkin Exp $

DISTNAME=	texlive.infra
PKGNAME=	mktexlsr-2020
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/tlnet/archive/}
DISTFILES=	${DISTNAME}.r${TEXLIVE_REV}${EXTRACT_SUFX} ${DISTNAME}.doc.r${TEXLIVE_REV}${EXTRACT_SUFX}
EXTRACT_SUFX=	.tar.xz
TEXLIVE_REV=	54630

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Create or rebuild ls-R
LICENSE=	public-domain

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/texmf-dist/scripts/texlive

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	mktexlsr
SUBST_SED.paths=	-e 's,kpsewhich,${PREFIX}/bin/kpsewhich,'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mktexlsr \
		${DESTDIR}${PREFIX}/bin/mktexlsr
	${INSTALL_MAN} ${WRKSRC}/../../doc/man/man1/mktexlsr.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mktexlsr.1

.include "../../mk/bsd.pkg.mk"
