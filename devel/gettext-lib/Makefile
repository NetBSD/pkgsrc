# $NetBSD: Makefile,v 1.34 2004/10/03 00:13:27 tv Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1998/08/09 15:13:33 kuriyama Exp
#

DISTNAME=		gettext-0.11.5
PKGNAME=		gettext-lib-0.11.5
SVR4_PKGNAME=		gttli
PKGREVISION=		4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gettext/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gettext/gettext.html
COMMENT=		Internationalized Message Handling Library (libintl)

CONFLICTS=		gettext<=0.10.35

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-included-gettext

CONFIGURE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

ALL_TARGET=		all-yes
INSTALL_TARGET=		install-exec
BUILD_DIRS=		${WRKSRC}/intl

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CPPFLAGS+=		-D_INTL_REDIRECT_MACROS=1 -DSTATIC=static
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
