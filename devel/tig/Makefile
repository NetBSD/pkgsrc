# $NetBSD: Makefile,v 1.15 2017/01/04 18:16:32 roy Exp $

DISTNAME=	tig-1.2.1
PKGREVISION=	3
CATEGORIES=	devel scm
MASTER_SITES=	http://jonas.nitro.dk/tig/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jonas.nitro.dk/tig/
COMMENT=	Ncurses-based GIT repository tool
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
DEPENDS+=	git-base-[0-9]*:../../devel/git-base

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
FAKE_NCURSES=	yes

CONF_FILES=	${EGDIR}/tigrc ${PKG_SYSCONFDIR}/tigrc
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

GIT_CONFIG=	${PREFIX}/bin/git-config
CONFIGURE_ENV+=	GIT_CONFIG=${GIT_CONFIG:Q}

CONFIGURE_ARGS+=		${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}
CONFIGURE_ARGS.gnu-iconv=	--with-libiconv=${BUILDLINK_PREFIX.iconv}

.include "../../mk/bsd.prefs.mk"
.if !empty(GLIBC_VERSION)
# Some version of glibc requires _XOPEN_SOURCE being defined to
# provide S_IFMT in <sys/stat.h>
CFLAGS+=	-D_XOPEN_SOURCE
# It is also required to define _BSD_SOURCE to get struct timezone
# defined in <sys/time.h>
CFLAGS+=	-D_BSD_SOURCE
.endif

BUILD_TARGET=	all doc
INSTALL_TARGET=	install install-doc

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}/${EGDIR} && \
	${INSTALL_DATA} ${WRKSRC}/contrib/tigrc ${DESTDIR}/${EGDIR}

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
