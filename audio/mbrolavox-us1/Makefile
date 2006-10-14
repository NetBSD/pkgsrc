# $NetBSD: Makefile,v 1.16 2006/10/14 07:59:09 wiz Exp $

DISTNAME=	us1-980512
PKGNAME=	mbrolavox-us1-980512
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://tcts.fpms.ac.be/pub/mbrola/VOICES/us1/ \
		http://www.festvox.org/mbrola/dba/us1/
EXTRACT_SUFX=	.zip

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://tcts.fpms.ac.be/synthesis/mbrola/
COMMENT=	American English female voice for MBROLA

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
	cd ${WRKSRC} && ${PAX} -rw us1 ${MHOME}

.include "../../mk/bsd.pkg.mk"
