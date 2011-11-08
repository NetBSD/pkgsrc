# $NetBSD: Makefile,v 1.1.1.1 2011/11/08 11:15:32 ryoon Exp $
#

DISTNAME=	coccigrep-1.6
CATEGORIES=	textproc
MASTER_SITES=	http://home.regit.org/wp-content/uploads/2011/08/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.regit.org/software/coccigrep/
COMMENT=	coccigrep is a semantic grep for the C language
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS=	coccinelle-[0-9]*:../../devel/coccinelle

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/coccigrep.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
