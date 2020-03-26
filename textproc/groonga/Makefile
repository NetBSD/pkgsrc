# $NetBSD: Makefile,v 1.68 2020/03/26 02:27:21 joerg Exp $
#

DISTNAME=	groonga-7.0.6
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://packages.groonga.org/source/groonga/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://groonga.org/
COMMENT=	Fulltext search engine and column store
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${RUBY_BASE}>=${RUBY_VERSION}:${RUBY_SRCDIR}

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
# for long file name
EXTRACT_USING=	bsdtar

.include "options.mk"

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-ruby=${RUBY}

PKGCONFIG_OVERRIDE+=	groonga.pc.in

PKG_SYSCONFSUBDIR=	${PKGBASE}

BUILD_DEFS+=		VARBASE

EXAMPLE_CONF_DIR=	${PREFIX}/share/examples/groonga

INSTALL_DIRS=		${BUILD_DIRS} vendor/onigmo-source
INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples

CONF_FILES+=		${EXAMPLE_CONF_DIR}/groonga.conf \
			${PKG_SYSCONFDIR}/groonga.conf
CONF_FILES+=		${EXAMPLE_CONF_DIR}/synonyms.tsv \
			${PKG_SYSCONFDIR}/synonyms.tsv

OWN_DIRS+=		${VARBASE}/log/${PKGBASE}

CHECK_WRKREF_SKIP+=		bin/groonga
CHECK_INTERPRETER_SKIP+=	share/groonga/examples/*

REPLACE_RUBY+=	data/munin/groonga_cpu_time_
REPLACE_RUBY+=	data/munin/groonga_disk_
REPLACE_RUBY+=	data/munin/groonga_n_records_
REPLACE_RUBY+=	data/munin/groonga_query_performance_
REPLACE_RUBY+=	data/munin/groonga_status_
REPLACE_RUBY+=	data/munin/groonga_throughput_

post-extract:
	rm ${WRKSRC}/version

.include "../../lang/ruby/replace.mk"
.include "../../devel/editline/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
