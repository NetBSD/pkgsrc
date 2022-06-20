# $NetBSD: Makefile,v 1.9 2022/06/20 07:40:39 nikita Exp $

DISTNAME=	rebar3-3.19.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=erlang/}
DIST_SUBDIR=	rebar3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/erlang/rebar3/
COMMENT=	Erlang build tool
LICENSE=	apache-2.0

USE_TOOLS+=	tar

REBAR_DEPS+=	bbmustache-1.12.2
REBAR_DEPS+=	certifi-2.9.0
REBAR_DEPS+=	cf-0.3.1
REBAR_DEPS+=	cth_readable-1.5.1
REBAR_DEPS+=	erlware_commons-1.5.0
REBAR_DEPS+=	eunit_formatters-0.5.0
REBAR_DEPS+=	getopt-1.0.1
REBAR_DEPS+=	providers-1.9.0
REBAR_DEPS+=	relx-4.7.0
REBAR_DEPS+=	ssl_verify_fun-1.1.6
REBAR_DEPS+=	meck-0.8.13

MAKE_ENV+=	HOME=${WRKDIR}
#MAKE_ENV+=	REBAR_NO_VERIFY_REPO_ORIGIN=1

DISTFILES=	${DEFAULT_DISTFILES}

.for dep in ${REBAR_DEPS}
DISTFILES+=		${dep}.tar
SITES.${dep}.tar=	https://repo.hex.pm/tarballs/
EXTRACT_DIR.${dep}.tar=	${WRKSRC}/_build/default/lib/${dep:C/-.*//}
.endfor

SUBST_CLASSES+=		escript
SUBST_STAGE.escript=	pre-configure
SUBST_MESSAGE.escript=	Fix default escript shebangh
SUBST_FILES.escript=	src/rebar_prv_escriptize.erl
SUBST_SED.escript=	-e 's,/usr/bin/env escript,${PREFIX}/bin/escript,'

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/examples/rebar3

post-extract:
.for dep in ${REBAR_DEPS}
	${MKDIR} ${WRKSRC}/_build/default/lib/${dep:C/-.*//}
	${TAR} xOf ${DISTDIR}/${DIST_SUBDIR}/${dep}.tar contents.tar.gz | ${TAR} xfz - -C ${WRKSRC}/_build/default/lib/${dep:C/-.*//}
	${MKDIR} ${WRKSRC}/_checkouts/${dep:C/-.*//}
	${TAR} xOf ${DISTDIR}/${DIST_SUBDIR}/${dep}.tar contents.tar.gz | ${TAR} xfz - -C ${WRKSRC}/_checkouts/${dep:C/-.*//}
.endfor
	${MKDIR} ${WRKSRC}/_build/bootstrap/lib
	${MKDIR} ${WRKSRC}/_build/bootstrap/plugins
.for dep in ${REBAR_DEPS}
	${LN} -sf ${WRKSRC}/_build/default/lib/${dep:C/-.*//} ${WRKSRC}/_build/bootstrap/lib/
.endfor
.for dep in ${REBAR_DEPS}
	${LN} -sf ${WRKSRC}/_build/default/plugins/${dep:C/-.*//} ${WRKSRC}/_build/bootstrap/plugins/
.endfor

do-build:
	#${RM} ${WRKSRC}/rebar.lock
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
