# $NetBSD: Makefile,v 1.49 2015/02/08 16:11:27 wiz Exp $

DISTNAME=	global-6.3.4
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
USE_LIBTOOL=		YES
USE_TOOLS+=		perl:run sort:run

CONF_FILES=	${PREFIX}/share/gtags/gtags.conf ${PKG_SYSCONFDIR}/gtags.conf

REPLACE_PYTHON+=	plugin-factory/pygments_parser.py

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
