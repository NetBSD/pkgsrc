# $NetBSD: Makefile,v 1.14 2002/10/09 10:27:29 jlam Exp $
#

DISTNAME=	OpenSP-1.4
PKGNAME=	opensp-1.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openjade/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://openjade.sourceforge.net/doc-1.4/index.htm
COMMENT=	SGML parser, successor to "sp"

CONFLICTS+=     sp-[0-9]*

USE_BUILDLINK2=		yes
USE_PERL5=		build
PTHREAD_OPTS+=		native

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-http \
			--enable-default-catalog=${PREFIX}/share/sgml/catalog

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
.  include "../../devel/unproven-pthreads/buildlink2.mk"
.endif

.include "../../mk/bsd.pkg.mk"
