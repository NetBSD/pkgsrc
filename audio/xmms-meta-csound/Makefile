# $NetBSD: Makefile,v 1.4 2004/01/20 12:07:43 agc Exp $
#

DISTNAME=		xmms-meta-csound-0.2
CATEGORIES=		audio
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		# empty
COMMENT=		XMMS meta input script for csound

DEPENDS+=		csound-[bd]*-[0-9]*:../../audio/csound-dev
DEPENDS+=		sox-[0-9]*:../../audio/sox

WRKSRC=			${WRKDIR}
USE_BUILDLINK2=		yes

do-build:
	${SED} "s,XXXPREFIXXXX,${PREFIX},g" \
		<${FILESDIR}/csound.sh >${WRKSRC}/csound.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/csound.sh ${PREFIX}/lib/xmms/Input/Meta

.include "../../audio/xmms-meta-input/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
