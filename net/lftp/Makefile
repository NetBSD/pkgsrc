# $NetBSD: Makefile,v 1.102 2013/02/06 23:23:17 jperkin Exp $

DISTNAME=		lftp-4.3.3
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		http://ftp.yars.free.net/pub/source/lftp/ \
			ftp://ftp.st.ryukoku.ac.jp/pub/network/ftp/lftp/ \
			http://lftp.cybermirror.org/

EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pettai@NetBSD.org
HOMEPAGE=		http://lftp.yar.ru/
COMMENT=		Powerful command line file transfer client
LICENSE=		gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		bison
MAKE_JOBS_SAFE=		no
USE_PKGLOCALEDIR=	YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_GNU_READLINE=	YES	# uses GNU readline internal _rl_mark_modified_lines

SHLIBTOOL_OVERRIDE=	# empty

.include "options.mk"

PLIST_SRC+=		${PKGDIR}/PLIST

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-modules

LDFLAGS.Darwin+=	-flat_namespace

.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=	yes
.endif

EGDIR=			${PREFIX}/share/examples/lftp
CONF_FILES=		${EGDIR}/lftp.conf.default ${PKG_SYSCONFDIR}/lftp.conf

INSTALLATION_DIRS=	bin lib/lftp ${PKGMANDIR}/man1 share/examples/lftp share/lftp

post-install: post-install-perl
	${INSTALL_DATA} ${WRKSRC}/lftp.conf ${DESTDIR}${EGDIR}/lftp.conf.default

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
