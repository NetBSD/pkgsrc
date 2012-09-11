# $NetBSD: Makefile,v 1.9 2012/09/11 23:59:37 asau Exp $
#

DISTNAME=	freepats-20060219
CATEGORIES=	audio
MASTER_SITES=	http://freepats.zenvoid.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freepats.zenvoid.org/
COMMENT=	Free patches (audio samples) for TiMidity

WRKSRC=		${WRKDIR}/freepats
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# empty
USE_TOOLS+=	pax

MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

INSTALLATION_DIRS=	share

post-patch:
	${ECHO} "dir ${PREFIX}/share/freepats" >${WRKSRC}/timidity.cfg
	cat ${WRKSRC}/freepats.cfg >>${WRKSRC}/timidity.cfg

do-install:
	cd ${WRKDIR} && pax -rw -pp freepats ${DESTDIR}${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
