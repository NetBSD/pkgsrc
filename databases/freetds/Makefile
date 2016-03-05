# $NetBSD: Makefile,v 1.56 2016/03/05 11:27:41 jperkin Exp $

DISTNAME=	freetds-0.91
PKGREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/Linux/ALPHA/freetds/stable/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freetds.org/
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
SUBST_STAGE.visibility+=	pre-configure
SUBST_MESSAGE.visibility+=	Turn off visibility for GCC 4.2
SUBST_FILES.visibility+=	src/tds/tds_checks.h
SUBST_FILES.visibility+=	include/*.h
SUBST_FILES.visibility+=	include/*/*.h
SUBST_SED.visibility+=		-e 's,!defined(__MINGW32__),!defined(__MINGW32__) \&\& !(__GNUC__ == 4 \&\& __GNUC_MINOR__ == 2),g'

pre-build:
	cd ${WRKSRC}/doc/doc && ln -sf ${DISTNAME} freetds

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
# rl_on_new_line, rl_reset_line_state
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
