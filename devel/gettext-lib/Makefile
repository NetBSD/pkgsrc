# $NetBSD: Makefile,v 1.17 2002/12/02 11:26:44 jlam Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1998/08/09 15:13:33 kuriyama Exp
#

DISTNAME=		gettext-0.11.5
PKGNAME=		gettext-lib-0.11.5
SVR4_PKGNAME=		gttli
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gettext/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gettext/gettext.html
COMMENT=		tools for providing messages in different languages, libintl only

CONFLICTS=		gettext<=0.10.35
DEPENDS+=		libiconv-[0-9]*:../../converters/libiconv

# gettext-lib is needed to bootstrap shell/bash2, which is needed to
# bootstrap buildlink2.
#
USE_BUILDLINK2=		no

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIGURE_ARGS+=	--with-included-gettext
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub
CONFIGURE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

ALL_TARGET=		all-yes
INSTALL_TARGET=		install-exec
BUILD_DIRS=		${WRKSRC}/intl

.include "../../mk/bsd.pkg.mk"

LDFLAGS:=	${LDFLAGS:N-L${LOCALBASE}/lib*}
