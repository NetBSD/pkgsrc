# $NetBSD: Makefile,v 1.2 2003/12/24 09:53:48 jmmv Exp $
#

DISTNAME=		xmms-meta-timidity-0.1
WRKSRC=			${WRKDIR}
CATEGORIES=		audio
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		# empty
COMMENT=		XMMS meta input script for timidity

DEPENDS+=		timidity-[0-9]*:../../audio/timidity
DEPENDS+=		eawpatches-[0-9]*:../../audio/eawpatches

USE_BUILDLINK2=		yes

do-build:
	${SED} "s,XXXPREFIXXXX,${PREFIX},g" \
		<${FILESDIR}/timidity.sh >${WRKSRC}/timidity.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/timidity.sh ${PREFIX}/lib/xmms/Input/Meta

.include "../../audio/xmms-meta-input/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
