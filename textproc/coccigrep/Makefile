# $NetBSD: Makefile,v 1.21 2024/10/13 10:10:23 wiz Exp $

DISTNAME=	coccigrep-1.20
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=regit/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://home.regit.org/software/coccigrep/
COMMENT=	Semantic grep for the C language
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	coccinelle-[0-9]*:../../devel/coccinelle

USE_LANGUAGES=	# none

INSTALLATION_DIRS=	${PKGMANDIR}/man1

PYTHON_VERSIONS_ACCEPTED=	311 310

post-install:
	${INSTALL_DATA} ${WRKSRC}/coccigrep.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
