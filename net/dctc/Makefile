# $NetBSD: Makefile,v 1.13 2003/06/02 01:18:01 jschauma Exp $
#

DISTNAME=	dctc-0.84.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.ac2i.tzo.com/dctc/ \
		http://brainz.servebeer.com/dctc/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.ac2i.tzo.com/dctc/
COMMENT=	Direct Connect clone (Direct Connect Text Client)

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
CONFIGURE_ARGS+=	--enable-manual-db-detect
REPLACE_PERL=	GDLjoiner
USE_PERL5=	YES
USE_GMAKE=	YES

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
