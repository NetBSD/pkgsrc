# $NetBSD: Makefile,v 1.8 2004/01/05 00:21:03 xtraeme Exp $
#

DISTNAME=	libgii-0.8.4.src
PKGNAME=	${DISTNAME:S/.src//}
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ggi-project.org/pub/packages/ggi/ggi/v2.0/ \
		http://www.ggi-project.org/ftp/ggi/v2.0/ \
		${MASTER_SITE_SOURCEFORGE:=ggi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@NetBSD.org
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
MAKE_DIRS+=		${PKG_SYSCONFDIR}/filter
CONF_FILES+=		${EGDIR}/filter/keytrans ${PKG_SYSCONFDIR}/filter/keytrans
CONF_FILES+=		${EGDIR}/filter/mouse ${PKG_SYSCONFDIR}/filter/mouse

.include "../../mk/bsd.pkg.mk"
