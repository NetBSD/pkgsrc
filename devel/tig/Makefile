# $NetBSD: Makefile,v 1.6 2012/10/31 11:19:50 asau Exp $
#

DISTNAME=	tig-0.17
CATEGORIES=	devel scm
MASTER_SITES=	http://jonas.nitro.dk/tig/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jonas.nitro.dk/tig/
COMMENT=	Ncurses-based GIT repository tool

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
DEPENDS+=	scmgit-[0-9]*:../../devel/scmgit

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_NCURSES=	yes

CONF_FILES=	${EGDIR}/tigrc ${PKG_SYSCONFDIR}/tigrc
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

GIT_CONFIG=	${PREFIX}/bin/git-config
CONFIGURE_ENV+=	GIT_CONFIG=${GIT_CONFIG:Q}

CONFIGURE_ARGS+=		${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}
CONFIGURE_ARGS.gnu-iconv=	--with-libiconv=${BUILDLINK_PREFIX.iconv}

BUILD_TARGET=	all doc
INSTALL_TARGET=	install install-doc

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}/${EGDIR} && \
	${INSTALL_DATA} ${WRKSRC}/contrib/tigrc ${DESTDIR}/${EGDIR}

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
