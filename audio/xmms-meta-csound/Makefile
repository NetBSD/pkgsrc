# $NetBSD: Makefile,v 1.1.1.1 2003/12/24 00:12:50 ben Exp $
#

DISTNAME=		xmms-meta-csound-0.1
WRKSRC=			${WRKDIR}
CATEGORIES=		audio
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		ben@netbsd.org
HOMEPAGE=		# empty
COMMENT=		XMMS meta input script for csound

DEPENDS+=		csound-dev-[0-9]*:../../audio/csound-dev
DEPENDS+=		sox-[0-9]*:../../audio/sox

USE_BUILDLINK2=		yes

do-build:
	${SED} "s,XXXPREFIXXXX,${PREFIX},g" \
		<${FILESDIR}/csound.sh >${WRKSRC}/csound.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/csound.sh ${PREFIX}/lib/xmms/Input/Meta

.include "../../audio/xmms-meta-input/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
