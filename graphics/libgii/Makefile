# $NetBSD: Makefile,v 1.5 2003/01/28 22:03:24 jlam Exp $
#

DISTNAME=	libgii-0.6
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ggi-project.org/pub/ggi/ggi/current/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.ggi-project.org/
COMMENT=	General Input Interface - API for all possible input sources

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
USE_X11=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-mutexes=int
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--sysconfdir="${PKG_SYSCONFDIR}"

PKG_SYSCONFSUBDIR=	ggi
EGDIR=			${PREFIX}/share/examples/ggi
CONF_FILES=		${EGDIR}/libgii.conf ${PKG_SYSCONFDIR}/libgii.conf

.include "../../mk/bsd.pkg.mk"
