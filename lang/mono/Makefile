# $NetBSD: Makefile,v 1.1.1.1 2003/03/01 13:11:44 jmmv Exp $
#

DISTNAME=	mono-0.21
CATEGORIES=	lang
MASTER_SITES=	http://www.go-mono.org/archive/

MAINTAINER=	marc@informatik.uni-bremen.de
HOMEPAGE=	http://www.go-mono.org/
COMMENT=	Open source implementation of the .NET Development Framework

# XXX: Is this really true?  As seen in the website, mono should work on
# other platforms; please test.
ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86
ONLY_FOR_PLATFORM+=	NetBSD-1.6[M-Z]-i386 NetBSD-[2-9]*-i386

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_PKGINSTALL=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/mono.pc.in

CONFIGURE_ARGS+=	--sysconfdir="${PKG_SYSCONFDIR}"

PKG_SYSCONFSUBDIR=	mono
EGDIR=		${PREFIX}/share/examples/mono
CONF_FILES=	${EGDIR}/config ${PKG_SYSCONFDIR}/config
CONF_FILES+=	${EGDIR}/machine.config ${PKG_SYSCONFDIR}/machine.config

.include "../../devel/boehm-gc/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
