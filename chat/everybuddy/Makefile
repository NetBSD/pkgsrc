# $NetBSD: Makefile,v 1.7 2003/08/09 17:11:04 seb Exp $

.include "Makefile.common"
PKGREVISION=	4

USE_BUILDLINK2=	yes
CONFLICTS+=	everybuddy-gnome-[0-9]*

.include "../../audio/esound/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

_ICONV_LIB=	${BUILDLINK_LIBICONV_LDADD:M-l*:C/-l//}
.if empty(_ICONV_LIB)
BUILDLINK_TRANSFORM+=	S:-liconv:
.endif
