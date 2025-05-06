# $NetBSD: Makefile,v 1.28 2025/05/06 20:53:38 vins Exp $

BYOBUVER=	5.133
DISTNAME=	byobu_${BYOBUVER}.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	misc
MASTER_SITES=	https://launchpad.net/byobu/trunk/${BYOBUVER}/+download/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.byobu.org/
COMMENT=	Open source text-based window manager and terminal multiplexer
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/byobu-${BYOBUVER}
GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	bash:run perl

REPLACE_BASH+=	usr/bin/*
REPLACE_BASH+=	usr/lib/byobu/*
REPLACE_BASH+=	usr/lib/byobu/include/*
REPLACE_BASH+=	usr/share/byobu/tests/*

REPLACE_PERL+=			usr/lib/byobu/include/*
REPLACE_PYTHON+=		usr/lib/byobu/include/*

EGDIR=			share/examples/byobu
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/${EGDIR}
EGFILES+=		byobu/backend \
			byobu/socketdir \
			profile.d/Z97-byobu.sh
# Keep empty directories
MAKE_DIRS+=		${PKG_SYSCONFBASE}/byobu ${PKG_SYSCONFBASE}/profile.d
.for i in ${EGFILES}
CONF_FILES+=		${EGDIR}/${i} ${PKG_SYSCONFBASE}/${i}
.endfor

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/application.mk"
.include "../../devel/py-newt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
