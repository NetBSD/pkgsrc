# $NetBSD: Makefile,v 1.5 2014/07/13 07:13:21 ryoon Exp $

BYOBUVER=	5.81
DISTNAME=	byobu_${BYOBUVER}.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	misc
MASTER_SITES=	http://byobu.co/download/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://byobu.co/download/
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

REPLACE_PERL+=	usr/lib/byobu/include/*
REPLACE_PYTHON+=	usr/lib/byobu/include/*
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-newt

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
