# $NetBSD: Makefile,v 1.100 2018/11/14 22:22:09 kleink Exp $

DISTNAME=	dc_gui2-0.80
PKGREVISION=	49
CATEGORIES=	net
#MASTER_SITES=	http://ac2i.homelinux.com/dctc/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://ac2i.homelinux.com/dctc/
COMMENT=	Graphical user interface for DCTC
LICENSE=	gnu-gpl-v2

DEPENDS+=	dctc>=0.85.9:../../net/dctc

BDB_ACCEPTED=		db4 db5
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config msgfmt
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-manual-db-detect

UNLIMIT_RESOURCES+=	datasize

CPPFLAGS+=		-I${BDBBASE}/include/${BDB_TYPE}
CPPFLAGS+=		-DNO_PRINTF_LOCALE
BUILDLINK_TRANSFORM+=	l:db4:${BDB_TYPE}

LDFLAGS.SunOS+=		-lsocket -lnsl

post-configure:
	${ECHO} '#ifndef MSG_NOSIGNAL' >> ${WRKSRC}/config.h
	${ECHO} '# define MSG_NOSIGNAL 0' >> ${WRKSRC}/config.h
	${ECHO} '#endif' >> ${WRKSRC}/config.h
	${TOUCH} ${WRKSRC}/stamp-h ${WRKSRC}/stamp-h.in

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
