# $NetBSD: Makefile,v 1.40 2016/02/26 11:40:30 jperkin Exp $

DISTNAME=	zebedee-2.5.3
PKGREVISION=	10
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zebedee/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.winton.org.uk/zebedee/
COMMENT=	Simple tunneling program for TCP or UDP with encryption

USE_TOOLS+=		gmake perl tclsh:run

MAKE_ENV+=		PERL5=${PERL5:Q}

MAKE_FLAGS.Darwin+=	OS=macosx
MAKE_FLAGS.*+=		OS=${LOWER_OPSYS:Q}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing tclsh paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	ftpgw.tcl
SUBST_SED.paths=	-e 's,tclsh,${TCLSH},g'

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
PTHREAD_CFLAGS+=  -DHAVE_PTHREADS
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
