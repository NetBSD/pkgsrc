# $NetBSD: Makefile,v 1.29 2009/06/13 06:46:42 rillig Exp $
#

DISTNAME=	global-5.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=global/} \
		http://www.tamacom.com/global/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/global/
COMMENT=	Source code tag system including web browser output

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
INFO_FILES=		YES
USE_TOOLS+=		perl:run

CONF_FILES=	${PREFIX}/share/gtags/gtags.conf ${PKG_SYSCONFDIR}/gtags.conf

.include "../../mk/bsd.pkg.mk"
