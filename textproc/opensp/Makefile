# $NetBSD: Makefile,v 1.31 2006/03/04 21:30:47 jlam Exp $
#

DISTNAME=	OpenSP-1.5.1
PKGNAME=	${DISTNAME:S/OpenSP/opensp/}
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openjade/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openjade.sourceforge.net/doc/index.htm
COMMENT=	SGML parser, successor to "sp"

CONFLICTS+=     sp-[0-9]*

BUILD_USES_MSGFMT=	yes
BROKEN_GETTEXT_DETECTION=	yes
USE_TOOLS+=		perl
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
PTHREAD_OPTS+=		require
USE_PKGLOCALEDIR=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-http \
			--enable-default-catalog=${PREFIX}/share/sgml/catalog

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
