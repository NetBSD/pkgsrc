# $NetBSD: Makefile,v 1.13 2023/05/26 16:33:04 bacon Exp $

DISTNAME=	auto-admin-0.7.15.17
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	d98521513284176fb24068a08df114e3264a17ec

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/auto-admin
COMMENT=	Portable tools for automating systems management
LICENSE=	2-clause-bsd

# auto-pkgsrc-prefix looks for pkg_add, which isn't guaranteed to be
# installed on NetBSD
DEPENDS+=	pkg_install>=0:../../pkgtools/pkg_install

USE_LANGUAGES=	# none

NO_BUILD=	yes

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_SED.prefix+=	-e 's|/usr/pkg|${PREFIX}|g'
SUBST_SED.prefix+=	-e 's|/usr/pkgsrc|${PKGSRCDIR}|g'
SUBST_FILES.prefix+=	User-scripts/auto-pkgsrc-prefix
SUBST_FILES.prefix+=	User-scripts/auto-pkgsrc-dir

.include "../../mk/bsd.pkg.mk"
