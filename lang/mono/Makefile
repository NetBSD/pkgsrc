# $NetBSD: Makefile,v 1.12 2003/12/03 00:12:12 recht Exp $
#

DISTNAME=	mono-0.28
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.go-mono.org/archive/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.go-mono.org/
COMMENT=	Open source implementation of the .NET Development Framework

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

# XXX please test
NOT_FOR_PLATFORM=	NetBSD-1.[0-5]*-*
NOT_FOR_PLATFORM+=	NetBSD-1.6-* NetBSD-1.6.*-*
NOT_FOR_PLATFORM+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[AB]-*

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_PKGINSTALL=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/libgc/libtool
PKGCONFIG_OVERRIDE=	mono.pc.in

CONFIGURE_ARGS+=	--with-gc=included
CONFIGURE_ARGS+=	--sysconfdir="${PKG_SYSCONFDIR}"

PKG_SYSCONFSUBDIR=	mono
EGDIR=		${PREFIX}/share/examples/mono
CONF_FILES=	${EGDIR}/config ${PKG_SYSCONFDIR}/config
CONF_FILES+=	${EGDIR}/machine.config ${PKG_SYSCONFDIR}/machine.config

.include "../../devel/glib2/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
