# $NetBSD: Makefile,v 1.21 2004/04/25 08:35:03 snj Exp $
#

DISTNAME=	dctc-0.85.4
CATEGORIES=	net
MASTER_SITES=	http://www.ac2i.tzo.com/dctc/ \
		http://brainz.servebeer.com/dctc/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ac2i.tzo.com/dctc/
COMMENT=	Direct Connect clone (Direct Connect Text Client)

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
CONFIGURE_ARGS+=	--enable-manual-db-detect
USE_PERL5=	YES
USE_GNU_TOOLS+=	make

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
