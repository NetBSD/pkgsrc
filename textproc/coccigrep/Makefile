# $NetBSD: Makefile,v 1.9 2014/05/09 07:37:21 wiz Exp $

DISTNAME=	coccigrep-1.12
CATEGORIES=	textproc
MASTER_SITES=	http://home.regit.org/wp-content/uploads/2011/08/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.regit.org/software/coccigrep/
COMMENT=	Semantic grep for the C language
LICENSE=	gnu-gpl-v3

DEPENDS=	coccinelle-[0-9]*:../../devel/coccinelle

USE_LANGUAGES=	# none

INSTALLATION_DIRS=	${PKGMANDIR}/man1

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.12

post-install:
	${INSTALL_DATA} ${WRKSRC}/coccigrep.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
