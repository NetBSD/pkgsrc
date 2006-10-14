# $NetBSD: Makefile,v 1.19 2006/10/14 07:59:09 wiz Exp $

DISTNAME=	en1-980910
PKGNAME=	mbrolavox-en1-980910
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://tcts.fpms.ac.be/pub/mbrola/VOICES/en1/ \
		http://www.festvox.org/mbrola/dba/en1/
EXTRACT_SUFX=	.zip

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://tcts.fpms.ac.be/synthesis/mbrola/
COMMENT=	British English male voice for MBROLA

DEPENDS+=	mbrola-301hnb1:../../audio/mbrola

LICENSE=	no-commercial-use

WRKSRC=		${WRKDIR}
NO_BUILD=	yes

MHOME=		${PREFIX}/share/mbrola/voices

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	${INSTALL_DATA_DIR} ${MHOME}
	cd ${WRKSRC} && ${PAX} -rw en1 ${MHOME}

.include "../../mk/bsd.pkg.mk"
