# $NetBSD: Makefile,v 1.6 2002/11/03 21:32:24 wiz Exp $
#

DISTNAME=	dc_gui-0.64
CATEGORIES=	net
MASTER_SITES=	http://www.ac2i.tzo.com/dctc/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ac2i.tzo.com/dctc/
COMMENT=	graphical user interface for DCTC

DEPENDS+=	dctc>=0.83.7:../../net/dctc

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
CONFIGURE_ARGS+=	--enable-manual-db-detect
USE_GMAKE=	YES

CPPFLAGS+=	-I${BUILDLINK_PREFIX.db4}/include/db4

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
