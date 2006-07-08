# $NetBSD: Makefile,v 1.61 2006/07/08 01:22:41 minskim Exp $
#

PKGREVISION=		6

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-esd

.if ${OPSYS} == "Darwin"
PLIST_SUBST+=	CDAUDIO="@comment "
.else
PLIST_SUBST+=	CDAUDIO=""
.endif

.include "../../mk/bsd.pkg.mk"
