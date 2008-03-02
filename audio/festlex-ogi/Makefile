# $NetBSD: Makefile,v 1.20 2008/03/02 06:10:31 jlam Exp $

DISTNAME=	OGIlexicon-2.0
PKGNAME=	festlex-ogi-2.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://cslu.cse.ogi.edu/pub/tts/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cslu.cse.ogi.edu/tts/
COMMENT=	Composite pronunciation dictionary from ogi.edu for festival

DEPENDS+=	festival>=1.4.0:../../audio/festival
DEPENDS+=	festlex-poslex>=1.4.0:../../audio/festlex-poslex

LICENSE=	no-commercial-use

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/festival
NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FHOME}
	cd ${WRKSRC} && ${PAX} -rw * ${DESTDIR}${FHOME}

.include "../../mk/bsd.pkg.mk"
