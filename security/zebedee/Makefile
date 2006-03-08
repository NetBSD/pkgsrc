# $NetBSD: Makefile,v 1.26 2006/03/08 23:12:41 minskim Exp $

DISTNAME=	zebedee-2.5.3
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zebedee/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.winton.org.uk/zebedee/
COMMENT=	Simple tunneling program for TCP or UDP with encryption

DEPENDS+=	tcl-[0-9]*:../../lang/tcl

USE_TOOLS+=		gmake perl

MAKE_ENV+=		PERL5=${PERL5:Q}

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
MAKE_FLAGS+=		OS=macosx
.else
MAKE_FLAGS+=		OS=${LOWER_OPSYS:Q}
.endif

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
PTHREAD_CFLAGS+=  -DHAVE_PTHREADS
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
