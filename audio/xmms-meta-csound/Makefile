# $NetBSD: Makefile,v 1.10 2005/06/16 06:57:40 jlam Exp $
#

DISTNAME=		xmms-meta-csound-0.3
CATEGORIES=		audio
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		# empty
COMMENT=		XMMS meta input script for csound

DEPENDS+=		csound4-[0-9]*:../../audio/csound4
DEPENDS+=		sox-[0-9]*:../../audio/sox
DEPENDS+=		xmms-meta-input-[0-9]*:../../audio/xmms-meta-input

WRKSRC=			${WRKDIR}
USE_LANGUAGES=		# empty
NO_CHECKSUM=		yes
INSTALLATION_DIRS=	lib/xmms/Input/Mesa

do-build:
	${SED} "s,XXXPREFIXXXX,${PREFIX},g" \
		<${FILESDIR}/csound.sh >${WRKSRC}/csound.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/csound.sh ${PREFIX}/lib/xmms/Input/Meta

.include "../../mk/bsd.pkg.mk"
