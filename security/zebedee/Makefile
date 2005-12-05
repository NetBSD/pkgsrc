# $NetBSD: Makefile,v 1.23 2005/12/05 20:50:58 rillig Exp $

DISTNAME=	zebedee-2.5.3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zebedee/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.winton.org.uk/zebedee/
COMMENT=	Simple tunneling program for TCP or UDP with encryption

DEPENDS+=	tcl-[0-9]*:../../lang/tcl

USE_TOOLS+=		gmake perl

MAKE_ENV+=		PERL5=${PERL5:Q}
MAKE_FLAGS+=		OS=${LOWER_OPSYS:Q}

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
PTHREAD_CFLAGS+=  -DHAVE_PTHREADS
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
