# $NetBSD: Makefile,v 1.1.1.1 2003/06/10 13:21:52 wiz Exp $
#

DISTNAME=	dc_gui2-0.74
CATEGORIES=	net
MASTER_SITES=	http://www.ac2i.tzo.com/dctc/ \
		http://brainz.servebeer.com/dctc/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.ac2i.tzo.com/dctc/
COMMENT=	graphical user interface for DCTC

DEPENDS+=	dctc>=0.83.9:../../net/dctc

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
CONFIGURE_ARGS+=	--enable-manual-db-detect
USE_GMAKE=		YES

CPPFLAGS+=	-I${BUILDLINK_PREFIX.db4}/include/db4
CPPFLAGS+=	-DNO_PRINTF_LOCALE

post-configure:
	@${ECHO} '#ifndef MSG_NOSIGNAL' >> ${WRKSRC}/config.h
	@${ECHO} '# define MSG_NOSIGNAL 0' >> ${WRKSRC}/config.h
	@${ECHO} '#endif' >> ${WRKSRC}/config.h
	@${ECHO} '#ifndef ENODATA' >> ${WRKSRC}/config.h
	@${ECHO} '# define ENODATA ENOMSG' >> ${WRKSRC}/config.h
	@${ECHO} '#endif' >> ${WRKSRC}/config.h
	@sleep 5
	@${TOUCH} ${WRKSRC}/stamp-h ${WRKSRC}/stamp-h.in

.include "../../converters/libiconv/buildlink2.mk"
.include "../../databases/db4/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
