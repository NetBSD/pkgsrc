# $NetBSD: Makefile,v 1.24 2025/12/11 09:24:20 wiz Exp $

DISTNAME=	festvox_ellpc11k
PKGNAME=	festvox-el11-1.4.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.cs.cmu.edu/festival/cstr/festival/1.4.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cstr.ed.ac.uk/projects/festival/
COMMENT=	Castilian Spanish male voice for the festival speech synthesis system
LICENSE=	no-commercial-use

DEPENDS+=	festival>=1.4.1:../../audio/festival

USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/festival
NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FHOME}
	cd ${WRKSRC} && pax -rw * ${DESTDIR}${FHOME}

.include "../../mk/bsd.pkg.mk"
