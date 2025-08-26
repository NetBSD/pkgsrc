# $NetBSD: Makefile,v 1.2 2025/08/26 22:23:49 gdt Exp $

.include "../../chat/jitsi-meet/Makefile.common"
# This package is a secondary target built from the jitsi-meet repo's
# distfile.

PKGNAME=	${GITHUB_PROJECT}-prosody-${JITSI_MEET_VERSION}
# The jitsi-meet repo distributes files with the same name as
# multiple other related repos, but with different contents.
DIST_SUBDIR=	jitsi-meet

COMMENT=	Additional plug-ins for Prosody from Jitsi Meet

USE_TOOLS=	gmake pax:build tar

DEPENDS+=	prosody-[0-9]*:../../chat/prosody

NO_BUILD=	yes

INSTALLATION_DIRS+=	share/jitsi-meet-prosody

do-install:
	cd ${WRKSRC}/resources/prosody-plugins && \
		${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/jitsi-meet-prosody

.include "../../mk/bsd.pkg.mk"
