# $NetBSD: Makefile,v 1.115 2016/03/05 11:29:07 jperkin Exp $

DISTNAME=	lftp-4.6.3a
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://lftp.yar.ru/ftp/ \
		ftp://ftp.tuwien.ac.at/infosys/browsers/ftp/lftp/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/ftp/lftp/ \
		ftp://ftp.st.ryukoku.ac.jp/pub/network/ftp/lftp/ \
		http://lftp.cybermirror.org/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://lftp.yar.ru/
COMMENT=	Powerful command line file transfer client
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		autoconf bison
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-modules

REPLACE_SH=		src/xdg-move
SHLIBTOOL_OVERRIDE=	# empty

.include "options.mk"

LDFLAGS.Darwin+=	-flat_namespace

EGDIR=			${PREFIX}/share/examples/lftp
CONF_FILES=		${EGDIR}/lftp.conf.default ${PKG_SYSCONFDIR}/lftp.conf

INSTALLATION_DIRS=	bin lib/lftp ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/examples/lftp share/lftp

pre-configure:
	cd ${WRKSRC} && autoconf

post-install: post-install-perl
	${INSTALL_DATA} ${WRKSRC}/lftp.conf ${DESTDIR}${EGDIR}/lftp.conf.default

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
# uses _rl_mark_modified_lines
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
