# $NetBSD: Makefile,v 1.28 2013/10/29 11:50:24 obache Exp $
#

DISTNAME=	groonga-3.0.9
CATEGORIES=	textproc
MASTER_SITES=	http://packages.groonga.org/source/groonga/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://groonga.org/
COMMENT=	Fulltext search engine and column store
LICENSE=	gnu-lgpl-v2.1

RUBY_VERSION_SUPPORTED=	200 193
.include "../../lang/ruby/rubyversion.mk"
DEPENDS+=	${RUBY_BASE}>=${RUBY_VERSION}:../../lang/${RUBY_BASE}

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
# for long file name
EXTRACT_USING=	bsdtar

.include "options.mk"

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-ruby19=${RUBY}

PKGCONFIG_OVERRIDE+=	groonga.pc.in

PKG_SYSCONFSUBDIR=	${PKGBASE}

BUILD_DEFS+=		VARBASE

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples

CONF_FILES+=		share/examples/${PKGBASE}/groonga.conf \
			${PKG_SYSCONFDIR}/groonga.conf

OWN_DIRS+=		${VARBASE}/log/${PKGBASE}

CHECK_WRKREF_SKIP+=	bin/groonga
CHECK_INTERPRETER_SKIP+=	share/groonga/examples/*

REPLACE_RUBY+=	data/munin/groonga_cpu_time
REPLACE_RUBY+=	data/munin/groonga_disk
REPLACE_RUBY+=	data/munin/groonga_n_records
REPLACE_RUBY+=	data/munin/groonga_query_performance
REPLACE_RUBY+=	data/munin/groonga_status
.include "../../lang/ruby/replace.mk"

.include "../../devel/editline/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
