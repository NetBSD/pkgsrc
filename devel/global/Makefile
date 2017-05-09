# $NetBSD: Makefile,v 1.65 2017/05/09 16:12:52 jperkin Exp $

DISTNAME=	global-6.5.6
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=global/}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/global/
COMMENT=	Source code tag system including web browser output
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-posix-sort=${SORT:Q}

INFO_FILES=		YES
USE_LANGUAGES=		c99
USE_LIBTOOL=		YES
USE_TOOLS+=		perl:run sort:run

CONF_FILES=	${PREFIX}/share/gtags/gtags.conf ${PKG_SYSCONFDIR}/gtags.conf

REPLACE_PYTHON+=	plugin-factory/pygments_parser.py

.include "options.mk"

.include "../../lang/python/application.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
