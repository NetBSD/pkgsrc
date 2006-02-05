# $NetBSD: Makefile,v 1.10 2006/02/05 23:08:18 joerg Exp $
#

DISTNAME=		xmms-meta-timidity-0.2
PKGREVISION=		2
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
USE_LANGUAGES=		# empty
NO_CHECKSUM=		yes
INSTALLATION_DIRS=	lib/xmms/Input/Meta

do-build:
	${SED} <${FILESDIR}/timidity.sh >${WRKSRC}/timidity.sh \
		-e "s,XXXPREFIXXXX,${PREFIX},g" \
		-e "s,XXXPKG_SYSCONFDIRXXX,${PKG_SYSCONFDIR},g"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/timidity.sh ${PREFIX}/lib/xmms/Input/Meta

.include "../../mk/bsd.pkg.mk"
