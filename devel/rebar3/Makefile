# $NetBSD: Makefile,v 1.11 2023/01/11 22:07:46 nikita Exp $

DISTNAME=	rebar3-3.20.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=erlang/}
DIST_SUBDIR=	rebar3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/erlang/rebar3/
COMMENT=	Erlang build tool
LICENSE=	apache-2.0

MAKE_ENV+=	HOME=${WRKDIR}

SUBST_CLASSES+=		escript
SUBST_STAGE.escript=	pre-configure
SUBST_MESSAGE.escript=	Fix default escript sha-bang
SUBST_FILES.escript=	apps/rebar/src/rebar_prv_escriptize.erl
SUBST_FILES.escript+=	apps/rebar/test/rebar_eunit_SUITE_data/deflate
SUBST_FILES.escript+=	apps/rebar/test/rebar_eunit_SUITE_data/inflate
SUBST_FILES.escript+=	bootstrap
SUBST_FILES.escript+=	rebar.config.sample
SUBST_FILES.escript+=	vendor/relx/priv/templates/install_upgrade_escript
SUBST_FILES.escript+=	vendor/relx/priv/templates/nodetool
SUBST_SED.escript=	-e 's,/usr/bin/env escript,${PREFIX}/bin/escript,'

SUBST_CLASSES+=		sh
SUBST_STAGE.escript=	pre-configure
SUBST_MESSAGE.escript=	Fix default sh sha-bang
SUBST_FILES.sh=		apps/rebar/src/rebar_prv_local_install.erl
SUBST_FILES.sh+=	pr2relnotes.sh
SUBST_FILES.sh+=	vendor/relx/priv/templates/bin
SUBST_FILES.sh+=	vendor/relx/priv/templates/builtin_hook_pid
SUBST_FILES.sh+=	vendor/relx/priv/templates/builtin_hook_status
SUBST_FILES.sh+=	vendor/relx/priv/templates/builtin_hook_wait_for_process
SUBST_FILES.sh+=	vendor/relx/priv/templates/builtin_hook_wait_for_vm_start
SUBST_FILES.sh+=	vendor/relx/priv/templates/erl_script
SUBST_FILES.sh+=	vendor/relx/priv/templates/extended_bin
SUBST_SED.escript=	-e 's,/usr/bin/env escript,${PREFIX}/bin/escript,'

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/examples/rebar3

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./bootstrap --offline

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rebar3 ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/manpages/rebar3.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/rebar.config.sample \
		${DESTDIR}${PREFIX}/share/examples/rebar3

do-test:
	cd ${WRKSRC} && \
		${SETENV} ./rebar3 escriptize && \
		${SETENV} ./rebar3 ct

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
