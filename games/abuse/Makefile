# $NetBSD: Makefile,v 1.29 2015/07/04 16:18:34 joerg Exp $

DISTNAME=		abuse_pd
PKGNAME=		abuse-2.0
PKGREVISION=		2
CATEGORIES=		games x11
MASTER_SITES=		http://public.planetmirror.com/pub/abuse/
DISTFILES=		${DISTNAME}.tgz abuse_data.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		# AWOL
COMMENT=		Full color 320x200 arcade quality platform shooter

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LDFLAGS=${X11_LDFLAGS:Q}
USE_TOOLS+=		gmake gtar
USE_LANGUAGES=		c c++

BROKEN_ON_PLATFORM=	NetBSD-*-arm32

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

post-extract:
	cd ${WRKSRC}/abuse						\
	&& ${GTAR} xfz ${DISTDIR}/abuse_data.tar.gz

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
