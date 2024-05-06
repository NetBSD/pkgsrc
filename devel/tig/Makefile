# $NetBSD: Makefile,v 1.27 2024/05/06 08:27:51 jperkin Exp $

DISTNAME=	tig-2.5.8
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_GITHUB:=jonas/}
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jonas.github.io/tig/
COMMENT=	Ncurses-based GIT repository tool
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
DEPENDS+=	git-base-[0-9]*:../../devel/git-base

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake gsed
USE_NCURSES=	yes	# Display issues with NetBSD curses(3)

CONF_FILES=	${EGDIR}/tigrc ${PKG_SYSCONFDIR}/tigrc
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

GIT_CONFIG=	${PREFIX}/bin/git-config
CONFIGURE_ENV+=	GIT_CONFIG=${GIT_CONFIG:Q}

CONFIGURE_ARGS+=		${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}
CONFIGURE_ARGS.gnu-iconv=	--with-libiconv=${BUILDLINK_PREFIX.iconv}

# FIXME:
MAKE_FLAGS+=	XMLTO_FLAGS=--skip-validation

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
TEST_TARGET=	test

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}/${EGDIR} && \
	${INSTALL_DATA} ${WRKSRC}/tigrc ${DESTDIR}/${EGDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
