# $NetBSD: Makefile,v 1.18 2004/02/14 17:21:53 jlam Exp $
#

DISTNAME=	OpenSP-1.5
PKGNAME=	opensp-1.5
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openjade/}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://openjade.sourceforge.net/doc/index.htm
COMMENT=	SGML parser, successor to "sp"

CONFLICTS+=     sp-[0-9]*

USE_BUILDLINK2=		yes
USE_PERL5=		build
USE_LIBTOOL=		yes
PTHREAD_OPTS+=		native

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-http \
			--enable-default-catalog=${PREFIX}/share/sgml/catalog

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
.  include "../../devel/unproven-pthreads/buildlink2.mk"
.endif

.include "../../mk/bsd.pkg.mk"
