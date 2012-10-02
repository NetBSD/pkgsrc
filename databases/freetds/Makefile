# $NetBSD: Makefile,v 1.48 2012/10/02 21:25:17 asau Exp $

DISTNAME=	freetds-0.91
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/Linux/ALPHA/freetds/stable/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freetds.org/
COMMENT=	Implementation of TDS protocol used by Sybase and MS-SQL servers
LICENSE=	gnu-lgpl-v2

USE_GNU_READLINE=	yes	# rl_on_new_line, rl_reset_line_state
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-tdsver=7.0
# no thread-safe resolver functions on NetBSD
CONFIGURE_ARGS+=	--disable-threadsafe

.include "../../mk/bsd.prefs.mk"

# Fails to build the shared lib on SunOS with -O2 or greater
.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-O[23]
.endif

EGDIR=		${PREFIX}/share/examples/freetds
CONF_FILES+=	${EGDIR}/freetds.conf ${PKG_SYSCONFDIR}/freetds.conf
CONF_FILES+=	${EGDIR}/locales.conf ${PKG_SYSCONFDIR}/locales.conf
CONF_FILES+=	${EGDIR}/pool.conf ${PKG_SYSCONFDIR}/pool.conf

# doc/Makefile ignores TARGET_DOCDIR for the files listed in
# nobase_data_DATA.  Make the Makefiles think the documentation is
# in doc/freetds through symlinks and by overriding DOCDIR.
MAKE_FLAGS+=		DOCDIR=doc/freetds
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} ETC=${DESTDIR}${EGDIR}

pre-build:
	cd ${WRKSRC}/doc/doc && ln -sf ${DISTNAME} freetds

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
