# $NetBSD: Makefile,v 1.8 2002/12/17 19:12:28 wiz Exp $
#

DISTNAME=	dctc-0.83.9
CATEGORIES=	net
MASTER_SITES=	http://www.ac2i.tzo.com/dctc/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ac2i.tzo.com/dctc/
COMMENT=	Direct Connect clone (Direct Connect Text Client)

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
CONFIGURE_ARGS+=	--enable-manual-db-detect
REPLACE_PERL=	GDLjoiner
USE_PERL5=	YES

CPPFLAGS+=	-I${BUILDLINK_PREFIX.db4}/include/db4

post-configure:
	@${ECHO} '#ifndef MSG_NOSIGNAL' >> ${WRKSRC}/config.h
	@${ECHO} '# define MSG_NOSIGNAL 0' >> ${WRKSRC}/config.h
	@${ECHO} '#endif' >> ${WRKSRC}/config.h
	@${ECHO} '#ifndef ENODATA' >> ${WRKSRC}/config.h
	@${ECHO} '# define ENODATA ENOMSG' >> ${WRKSRC}/config.h
	@${ECHO} '#endif' >> ${WRKSRC}/config.h

.include "../../databases/db4/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
