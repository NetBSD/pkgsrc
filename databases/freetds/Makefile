# $NetBSD: Makefile,v 1.79 2024/05/16 06:14:39 wiz Exp $

DISTNAME=	freetds-1.00.112
PKGREVISION=	13
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.freetds.org/pub/freetds/stable/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freetds.org/
COMMENT=	Implementation of TDS protocol used by Sybase and MS-SQL servers
LICENSE=	gnu-lgpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-tdsver=7.0
# no thread-safe resolver functions on NetBSD
CONFIGURE_ARGS+=	--disable-threadsafe
TEST_TARGET=		check

# Fails to build the shared lib on SunOS with -O2 or greater
BUILDLINK_TRANSFORM.SunOS+=	rm:-O[23]

EGDIR=		${PREFIX}/share/examples/freetds
CONF_FILES+=	${EGDIR}/freetds.conf ${PKG_SYSCONFDIR}/freetds.conf
CONF_FILES+=	${EGDIR}/locales.conf ${PKG_SYSCONFDIR}/locales.conf
CONF_FILES+=	${EGDIR}/pool.conf ${PKG_SYSCONFDIR}/pool.conf

# doc/Makefile ignores TARGET_DOCDIR for the files listed in
# nobase_data_DATA.  Make the Makefiles think the documentation is
# in doc/freetds through symlinks and by overriding DOCDIR.
MAKE_FLAGS+=		DOCDIR=doc/freetds
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} ETC=${DESTDIR}${EGDIR}

SUBST_CLASSES+=			visibility
SUBST_STAGE.visibility=		pre-configure
SUBST_MESSAGE.visibility=	Turn off visibility for GCC 4.2
SUBST_FILES.visibility+=	include/freetds/odbc.h \
				include/freetds/popvis.h \
				include/freetds/pushvis.h
SUBST_SED.visibility+=		-e 's,!defined(__MINGW32__),!defined(__MINGW32__) \&\& !(__GNUC__ == 4 \&\& __GNUC_MINOR__ == 2),g'

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
# rl_on_new_line, rl_reset_line_state
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
