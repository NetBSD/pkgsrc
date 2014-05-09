# $NetBSD: Makefile,v 1.3 2014/05/09 07:37:11 wiz Exp $

DISTNAME=	byobu_5.69.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	misc
MASTER_SITES=	http://byobu.co/download/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://byobu.co/download/
COMMENT=	Open source text-based window manager and terminal multiplexer
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/byobu-5.69
GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	automake bash:run perl

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

BYOBU_IN_FILES+=	usr/bin/byobu-config.in \
			usr/bin/byobu-ctrl-a.in \
			usr/bin/byobu-disable-prompt.in \
			usr/bin/byobu-disable.in \
			usr/bin/byobu-enable-prompt.in \
			usr/bin/byobu-enable.in \
			usr/bin/byobu-export.in \
			usr/bin/byobu-janitor.in \
			usr/bin/byobu-launch.in \
			usr/bin/byobu-launcher-install.in \
			usr/bin/byobu-launcher-uninstall.in \
			usr/bin/byobu-launcher.in \
			usr/bin/byobu-layout.in \
			usr/bin/byobu-prompt.in \
			usr/bin/byobu-quiet.in \
			usr/bin/byobu-reconnect-sockets.in \
			usr/bin/byobu-select-backend.in \
			usr/bin/byobu-select-profile.in \
			usr/bin/byobu-select-session.in \
			usr/bin/byobu-shell.in \
			usr/bin/byobu-silent.in \
			usr/bin/byobu-status-detail.in \
			usr/bin/byobu-status.in \
			usr/bin/byobu-ugraph.in \
			usr/bin/byobu-ulevel.in \
			usr/bin/byobu.in \
			etc/profile.d/Z97-byobu.sh.in \
			usr/lib/byobu/include/dirs.in \
			usr/lib/byobu/include/toggle-utf8.in \
			usr/share/byobu/tests/byobu-time-notifications.in \
			usr/lib/byobu/include/config.py.in

post-extract:
.for i in ${BYOBU_IN_FILES}
	cd ${WRKSRC} && ${MV} ${i:S/.in$//} ${i}
.endfor

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; automake -a --foreign -i; autoconf

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/application.mk"
.include "../../devel/py-newt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
