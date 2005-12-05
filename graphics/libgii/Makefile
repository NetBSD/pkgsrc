# $NetBSD: Makefile,v 1.21 2005/12/05 23:55:09 rillig Exp $

DISTNAME=	libgii-0.9.1.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ggi-project.org/pub/packages/ggi/ggi/v2.1/ \
		http://www.ggi-project.org/ftp/ggi/v2.1/ \
		${MASTER_SITE_SOURCEFORGE:=ggi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ggi-project.org/
COMMENT=	General Input Interface - API for all possible input sources

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_PKGINSTALL=		yes
USE_LIBTOOL=		yes
TEST_TARGET=		check

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

PKG_SYSCONFSUBDIR=	ggi
EGDIR=			${PREFIX}/share/examples/ggi
CONF_FILES=		${EGDIR}/libgii.conf ${PKG_SYSCONFDIR}/libgii.conf
MAKE_DIRS+=		${PKG_SYSCONFDIR}/filter
CONF_FILES+=		${EGDIR}/filter/keytrans ${PKG_SYSCONFDIR}/filter/keytrans
CONF_FILES+=		${EGDIR}/filter/mouse ${PKG_SYSCONFDIR}/filter/mouse

PTHREAD_OPTS+=		native

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.if empty(PTHREAD_TYPE:Mnative)
PLIST_SUBST+=		GGTICK=""
.else
PLIST_SUBST+=		GGTICK="@comment "
.endif

.include "../../mk/bsd.pkg.mk"
