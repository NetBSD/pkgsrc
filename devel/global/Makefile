# $NetBSD: Makefile,v 1.34 2012/12/08 23:51:04 wiz Exp $
#

DISTNAME=	global-6.2.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=global/}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/global/
COMMENT=	Source code tag system including web browser output
LICENSE=	gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-posix-sort=${SORT:Q}

INFO_FILES=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		perl:run sort:run

CONF_FILES=	${PREFIX}/share/gtags/gtags.conf ${PKG_SYSCONFDIR}/gtags.conf

.include "../../mk/bsd.pkg.mk"
