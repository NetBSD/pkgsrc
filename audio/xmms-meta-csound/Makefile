# $NetBSD: Makefile,v 1.5 2004/03/12 02:36:09 snj Exp $
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
DEPENDS+=		xmms-meta-input-[0-9]*:../../audio/xmms-meta-input

WRKSRC=			${WRKDIR}
NO_BUILDLINK=		# defined
USE_LANGUAGES=		# empty

do-build:
	${SED} "s,XXXPREFIXXXX,${PREFIX},g" \
		<${FILESDIR}/csound.sh >${WRKSRC}/csound.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/csound.sh ${PREFIX}/lib/xmms/Input/Meta

.include "../../mk/bsd.pkg.mk"
