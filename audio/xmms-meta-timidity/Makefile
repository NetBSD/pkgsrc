# $NetBSD: Makefile,v 1.4 2004/03/12 02:47:51 snj Exp $
#

DISTNAME=		xmms-meta-timidity-0.1
CATEGORIES=		audio
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		# empty
COMMENT=		XMMS meta input script for timidity

DEPENDS+=		timidity-[0-9]*:../../audio/timidity
DEPENDS+=		eawpatches-[0-9]*:../../audio/eawpatches
DEPENDS+=		xmms-meta-input-[0-9]*:../../audio/xmms-meta-input

WRKSRC=			${WRKDIR}
NO_BUILDLINK=		# defined
USE_LANGUAGES=		# empty

do-build:
	${SED} "s,XXXPREFIXXXX,${PREFIX},g" \
		<${FILESDIR}/timidity.sh >${WRKSRC}/timidity.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/timidity.sh ${PREFIX}/lib/xmms/Input/Meta

.include "../../mk/bsd.pkg.mk"
