# $NetBSD: Makefile,v 1.7 1999/12/28 04:19:58 wiz Exp $

DISTNAME=	festlex_CMU
PKGNAME=	festlex-cmu-1.4.0
WRKSRC=		${WRKDIR}/festival
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cstr.ed.ac.uk/pub/festival/1.4.0/

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival.html

DEPENDS+=	festival-1.4.0:../festival

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ ${FIND} ${WRKSRC} -type d -print0 | xargs -0 ${CHMOD} 755

do-install:
	${INSTALL_DATA_DIR} ${FHOME}
	cd ${WRKSRC} && ${PAX} -r -w * ${FHOME}

.include "../../mk/bsd.pkg.mk"
