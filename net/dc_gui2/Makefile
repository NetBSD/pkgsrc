# $NetBSD: Makefile,v 1.15 2004/03/08 19:40:41 jmmv Exp $
#

DISTNAME=	dc_gui2-0.75
PKGREVISION=	7
CATEGORIES=	net
MASTER_SITES=	http://www.ac2i.tzo.com/dctc/ \
		http://brainz.servebeer.com/dctc/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ac2i.tzo.com/dctc/
COMMENT=	Graphical user interface for DCTC

DEPENDS+=	dctc>=0.85.4:../../net/dctc
DEPENDS+=	xdg-dirs>=1.1:../../misc/xdg-dirs

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
CONFIGURE_ARGS+=	--enable-manual-db-detect
USE_GNU_TOOLS+=		make

CPPFLAGS+=	-I${BUILDLINK_PREFIX.db4}/include/db4
CPPFLAGS+=	-DNO_PRINTF_LOCALE

post-configure:
	@${ECHO} '#ifndef MSG_NOSIGNAL' >> ${WRKSRC}/config.h
	@${ECHO} '# define MSG_NOSIGNAL 0' >> ${WRKSRC}/config.h
	@${ECHO} '#endif' >> ${WRKSRC}/config.h
	@sleep 5
	@${TOUCH} ${WRKSRC}/stamp-h ${WRKSRC}/stamp-h.in

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
