# $NetBSD: Makefile,v 1.21 2004/05/29 20:45:34 kristerw Exp $
#

DISTNAME=	OpenSP-1.5.1
PKGNAME=	${DISTNAME:S/OpenSP/opensp/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openjade/}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://openjade.sourceforge.net/doc/index.htm
COMMENT=	SGML parser, successor to "sp"

CONFLICTS+=     sp-[0-9]*

USE_BUILDLINK3=		yes
USE_PERL5=		build
USE_LIBTOOL=		yes
PTHREAD_OPTS+=		require

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-http \
			--enable-default-catalog=${PREFIX}/share/sgml/catalog

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
