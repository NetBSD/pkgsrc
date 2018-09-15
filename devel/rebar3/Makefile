# $NetBSD: Makefile,v 1.2 2018/09/15 13:56:15 tnn Exp $

DISTNAME=	rebar3-3.6.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=erlang/}
DIST_SUBDIR=	rebar3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/erlang/rebar3/
COMMENT=	Erlang build tool
LICENSE=	apache-2.0

USE_TOOLS+=	tar

REBAR_DEPS=     bbmustache-1.5.0 \
		certifi-2.0.0 \
		cf-0.2.2 \
		cth_readable-1.4.2 \
		erlware_commons-1.2.0 \
		eunit_formatters-0.5.0 \
		getopt-1.0.1 \
		providers-1.7.0 \
		relx-3.26.0 \
		ssl_verify_fun-1.1.3

DISTFILES=	${DEFAULT_DISTFILES}

.for dep in ${REBAR_DEPS}
DISTFILES+=		${dep}.tar
SITES.${dep}.tar=	https://repo.hex.pm/tarballs/
EXTRACT_DIR.${dep}.tar=	${WRKSRC}/_build/default/lib/${dep:C/-.*//}
.endfor

DISTFILES+=				${DISTNAME:S/-/-cache-/}.tar.gz
SITES.${DISTNAME:S/-/-cache-/}.tar.gz=	https://ftp.netbsd.org/pub/NetBSD/misc/fhajny/

SUBST_CLASSES+=		escript
SUBST_STAGE.escript=	pre-configure
SUBST_MESSAGE.escript=	Fix default escript shebangh
SUBST_FILES.escript=	src/rebar_prv_escriptize.erl
SUBST_SED.escript=	-e 's,/usr/bin/env escript,${PREFIX}/bin/escript,'

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/examples/rebar3

post-extract:
	${MKDIR} -p ${WRKSRC}/_build/bootstrap/lib
.for dep in ${REBAR_DEPS}
	cd ${WRKSRC}/_build/default/lib/${dep:C/-.*//} && \
		${TAR} -xzf contents.tar.gz
	${LN} -sf ../../default/lib/${dep:C/-.*//} \
		${WRKSRC}/_build/bootstrap/lib/${dep:C/-.*//}
.endfor

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./bootstrap

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rebar3 ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/manpages/rebar3.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/rebar.config.sample \
		${DESTDIR}${PREFIX}/share/examples/rebar3

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
