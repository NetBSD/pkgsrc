# $NetBSD: Makefile,v 1.14 2005/02/21 20:26:11 hubertf Exp $

DISTNAME=	libgii-0.8.6.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ggi-project.org/pub/packages/ggi/ggi/v2.0/ \
		http://www.ggi-project.org/ftp/ggi/v2.0/ \
		${MASTER_SITE_SOURCEFORGE:=ggi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ggi-project.org/
COMMENT=	General Input Interface - API for all possible input sources

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_X11=		yes
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-mutexes=int
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--sysconfdir="${PKG_SYSCONFDIR}"

PKG_SYSCONFSUBDIR=	ggi
EGDIR=			${PREFIX}/share/examples/ggi
CONF_FILES=		${EGDIR}/libgii.conf ${PKG_SYSCONFDIR}/libgii.conf
MAKE_DIRS+=		${PKG_SYSCONFDIR}/filter
CONF_FILES+=		${EGDIR}/filter/keytrans ${PKG_SYSCONFDIR}/filter/keytrans
CONF_FILES+=		${EGDIR}/filter/mouse ${PKG_SYSCONFDIR}/filter/mouse

.include "../../mk/bsd.pkg.mk"
