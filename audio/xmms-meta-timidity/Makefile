# $NetBSD: Makefile,v 1.16 2012/02/15 23:16:32 hans Exp $
#

DISTNAME=		xmms-meta-timidity-0.2
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		# empty
COMMENT=		XMMS meta input script for timidity

DEPENDS+=		timidity-[0-9]*:../../audio/timidity
DEPENDS+=		freepats-[0-9]*:../../audio/freepats
DEPENDS+=		xmms-meta-input-[0-9]*:../../audio/xmms-meta-input

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}
USE_LANGUAGES=		# empty
INSTALLATION_DIRS=	lib/xmms/Input/Meta

do-build:
	${SED} <${FILESDIR}/timidity.sh >${WRKSRC}/timidity.sh \
		-e "s,XXXPREFIXXXX,${PREFIX},g" \
		-e "s,XXXPKG_SYSCONFDIRXXX,${PKG_SYSCONFDIR},g" \
		-e "s,XXXPKG_SHXXX,${TOOLS_PATH.sh},g"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/timidity.sh \
		${DESTDIR}${PREFIX}/lib/xmms/Input/Meta

.include "../../mk/bsd.pkg.mk"
