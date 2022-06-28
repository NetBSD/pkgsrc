# $NetBSD: Makefile,v 1.142 2022/06/28 11:35:01 wiz Exp $

DISTNAME=	lftp-4.9.2
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	http://lftp.yar.ru/ftp/
MASTER_SITES+=	ftp://ftp.st.ryukoku.ac.jp/pub/network/ftp/lftp/
MASTER_SITES+=	http://lftp.cybermirror.org/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://lftp.tech/
COMMENT=	Powerful command line file transfer client
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		autoconf bison
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-modules
CONFIGURE_ENV+=		readline_prefix=${BUILDLINK_DIR}

SUBST_CLASSES+=			readline
SUBST_STAGE.readline=		pre-configure
SUBST_MESSAGE.readline=		Detect pkgsrc readline
SUBST_FILES.readline+=		configure
SUBST_SED.readline+=		-e 's,/usr/local,${BUILDLINK_DIR},g'

REPLACE_SH=		src/xdg-move
SHLIBTOOL_OVERRIDE=	# empty

.include "options.mk"

EGDIR=			${PREFIX}/share/examples/lftp
CONF_FILES=		${EGDIR}/lftp.conf.default ${PKG_SYSCONFDIR}/lftp.conf

INSTALLATION_DIRS=	bin lib/lftp ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/examples/lftp share/lftp

post-install: post-install-perl
	${INSTALL_DATA} ${WRKSRC}/lftp.conf ${DESTDIR}${EGDIR}/lftp.conf.default

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
# uses _rl_mark_modified_lines and GNU history(3) functions
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
