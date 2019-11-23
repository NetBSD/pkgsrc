# $NetBSD: Makefile,v 1.25 2019/11/23 12:09:43 nia Exp $

DISTNAME=	festlex_OALD
PKGNAME=	festlex-oald-2.5
CATEGORIES=	audio
MASTER_SITES=	http://festvox.org/packed/festival/${PKGVERSION_NOREV}/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://festvox.org/festival/index.html
COMMENT=	Oxford Advanced Learner's pronunciation dictionary for Festival
LICENSE=	no-commercial-use

DEPENDS+=	festival>=1.4.0:../../audio/festival

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
