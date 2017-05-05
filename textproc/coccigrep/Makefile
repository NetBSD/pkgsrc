# $NetBSD: Makefile,v 1.14 2017/05/05 11:04:15 leot Exp $

DISTNAME=	coccigrep-1.16
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=regit/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.regit.org/software/coccigrep/
COMMENT=	Semantic grep for the C language
LICENSE=	gnu-gpl-v3

DEPENDS=	coccinelle-[0-9]*:../../devel/coccinelle

USE_LANGUAGES=	# none

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/coccigrep.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
