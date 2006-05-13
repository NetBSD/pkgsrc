# $NetBSD: Makefile,v 1.3 2006/05/13 13:38:34 wiz Exp $
#

DISTNAME=	freepats-20060219
CATEGORIES=	audio
MASTER_SITES=	http://freepats.opensrc.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://freepats.opensrc.org/
COMMENT=	Free patches (audio samples) for TiMidity

WRKSRC=		${WRKDIR}/freepats
NO_CONFIGURE=	yes
NO_BUILD=	yes

MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

INSTALLATION_DIRS=	share

post-patch:
	${ECHO} "dir ${PREFIX}/share/freepats" >${WRKSRC}/timidity.cfg
	${CAT} ${WRKSRC}/freepats.cfg >>${WRKSRC}/timidity.cfg

do-install:
	cd ${WRKDIR} && ${PAX} -rw -pe freepats ${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
