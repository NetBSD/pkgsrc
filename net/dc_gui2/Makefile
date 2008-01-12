# $NetBSD: Makefile,v 1.40 2008/01/12 11:56:41 wiz Exp $
#

DISTNAME=	dc_gui2-0.75
PKGREVISION=	22
CATEGORIES=	net
MASTER_SITES=	http://ac2i.homelinux.com/dctc/ \
		http://dc.tddm.se/clients/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ac2i.homelinux.com/dctc/
COMMENT=	Graphical user interface for DCTC

DEPENDS+=	dctc>=0.85.4:../../net/dctc

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	YES
CONFIGURE_ARGS+=	--enable-manual-db-detect
USE_TOOLS+=		gmake pkg-config msgfmt
USE_LIBTOOL=		YES

UNLIMIT_RESOURCES+=	datasize

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
.include "../../mk/bsd.pkg.mk"
