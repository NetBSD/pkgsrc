# $NetBSD: Makefile,v 1.28 2006/01/06 15:10:06 wiz Exp $
#

DISTNAME=	dctc-0.85.4
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.ac2i.tzo.com/dctc/ \
		http://brainz.servebeer.com/dctc/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ac2i.tzo.com/dctc/
COMMENT=	Direct Connect clone (Direct Connect Text Client)

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-manual-db-detect
USE_TOOLS+=		gmake perl:run

CPPFLAGS+=	-I${BUILDLINK_PREFIX.db4}/include/db4

post-configure:
	@${TOUCH} ${WRKSRC}/stamp-h.in ${WRKSRC}/config.h.in
	@${TOUCH} ${WRKSRC}/config.status ${WRKSRC}/stamp-h
	@${ECHO} '#ifndef MSG_NOSIGNAL' >> ${WRKSRC}/config.h
	@${ECHO} '# define MSG_NOSIGNAL 0' >> ${WRKSRC}/config.h
	@${ECHO} '#endif' >> ${WRKSRC}/config.h

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
