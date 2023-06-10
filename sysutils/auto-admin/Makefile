# $NetBSD: Makefile,v 1.14 2023/06/10 12:59:02 bacon Exp $

DISTNAME=	auto-admin-0.7.16
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}

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
