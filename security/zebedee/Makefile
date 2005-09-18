# $NetBSD: Makefile,v 1.22 2005/09/18 13:51:09 taca Exp $

DISTNAME=	zebedee-2.5.3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zebedee/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.winton.org.uk/zebedee/
COMMENT=	Simple tunneling program for TCP or UDP with encryption

DEPENDS+=	tcl-[0-9]*:../../lang/tcl

USE_TOOLS+=		gmake perl

MAKE_ENV+=		PERL5=${PERL5}
MAKE_FLAGS=		OS=${LOWER_OPSYS}

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
PTHREAD_CFLAGS+=  -DHAVE_PTHREADS
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
