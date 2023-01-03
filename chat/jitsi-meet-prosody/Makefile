# $NetBSD: Makefile,v 1.1 2023/01/03 10:25:06 khorben Exp $

.include "../../chat/jitsi-meet/Makefile.common"

PKGNAME=	${GITHUB_PROJECT}-prosody-${JITSI_MEET_VERSION}

COMMENT=	Additional plug-ins for Prosody from Jitsi Meet

USE_TOOLS=	gmake pax:build tar

DEPENDS+=	prosody-[0-9]*:../../chat/prosody

NO_BUILD=	yes

INSTALLATION_DIRS+=	share/jitsi-meet-prosody

do-install:
	cd ${WRKSRC}/resources/prosody-plugins && \
		${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/jitsi-meet-prosody

.include "../../mk/bsd.pkg.mk"
