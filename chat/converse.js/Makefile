# $NetBSD: Makefile,v 1.1 2025/03/15 01:09:02 manu Exp $

DISTNAME=	converse.js-10.1.8
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=conversejs/converse.js/releases/download/v10.1.8/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://conversejs.org/
COMMENT=	Free and open-source XMPP chat client in your browser
LICENSE=	mpl-2.0

WRKSRC=			${WRKDIR}/package
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pax
USE_LANGUAGES=		# none
NO_BUILD=		yes

CONVERSEJSDIR=	share/converse.js

do-install:
	cd ${WRKSRC}/dist && ${FIND} . -type f | \
                ${PAX} -rw -pmp ${DESTDIR}${PREFIX}/${CONVERSEJSDIR}

.include "../../mk/bsd.pkg.mk"
