# $NetBSD: Makefile,v 1.62 2006/08/28 05:09:05 ben Exp $
#

PKGREVISION=		6

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-esd

.if ${OPSYS} == "Darwin"
PLIST_SUBST+=	CDAUDIO="@comment "
_INSTALL_UNSTRIPPED=	yes
.else
PLIST_SUBST+=	CDAUDIO=""
.endif

.include "../../mk/bsd.pkg.mk"
