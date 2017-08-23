# $NetBSD: Makefile,v 1.33 2017/08/23 17:53:55 jlam Exp $

DISTNAME=	cdlabelgen-4.3.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.aczoom.com/pub/tools/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.aczoom.com/tools/cdinsert/
COMMENT=	Generate frontcards and traycards for CDs

USE_TOOLS+=	perl:run
USE_LANGUAGES=	# empty
REPLACE_PERL+=	cdlabelgen

MAKE_FLAGS+=	BASE_DIR=${DESTDIR:Q}${PREFIX:Q}
MAKE_FLAGS+=	MAN_DIR=${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR:Q}
MAKE_FLAGS+=	INSTALL=${INSTALL_SCRIPT:Q}
MAKE_FLAGS+=	INSTALL_FILE=${INSTALL_DATA:Q}
MAKE_FLAGS+=	INSTALL_MAN=${INSTALL_MAN:Q}

INSTALLATION_DIRS=	bin share/cdlabelgen ${PKGMANDIR}/man1

post-extract:
	cd ${WRKSRC} && ${CHMOD} go+r *

post-build:
	cd ${WRKSRC} && \
	${SED} -e "s,@PREFIX@,${PREFIX},g" cdlabelgen > cdlabelgen.new && \
	${MV} cdlabelgen.new cdlabelgen

.include "../../mk/bsd.pkg.mk"
