# $NetBSD: Makefile,v 1.7 2002/11/11 14:01:32 wiz Exp $
#

DISTNAME=	dc_gui-0.65
CATEGORIES=	net
MASTER_SITES=	http://www.ac2i.tzo.com/dctc/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ac2i.tzo.com/dctc/
COMMENT=	graphical user interface for DCTC

DEPENDS+=	dctc>=0.83.8:../../net/dctc

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
CONFIGURE_ARGS+=	--enable-manual-db-detect
USE_GMAKE=	YES

CPPFLAGS+=	-I${BUILDLINK_PREFIX.db4}/include/db4
CPPFLAGS+=	-DNO_PRINTF_LOCALE

post-configure:
	@${ECHO} '#ifndef MSG_NOSIGNAL' >> ${WRKSRC}/config.h
	@${ECHO} '# define MSG_NOSIGNAL 0' >> ${WRKSRC}/config.h
	@${ECHO} '#endif' >> ${WRKSRC}/config.h
	@${ECHO} '#ifndef ENODATA' >> ${WRKSRC}/config.h
	@${ECHO} '# define ENODATA ENOMSG' >> ${WRKSRC}/config.h
	@${ECHO} '#endif' >> ${WRKSRC}/config.h

.include "../../converters/libiconv/buildlink2.mk"
.include "../../databases/db4/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
