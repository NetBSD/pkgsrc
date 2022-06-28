# $NetBSD: Makefile,v 1.6 2022/06/28 11:30:58 wiz Exp $

GITHUB_PROJECT=	FlameGraph
DISTNAME=	flamegraph-1.0
PKGREVISION=	5
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_GITHUB:=brendangregg/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.brendangregg.com/flamegraphs.html
COMMENT=	Stack trace visualizer
LICENSE=	cddl-1.0 AND apache-2.0

USE_TOOLS+=	perl

USE_LANGUAGES=	# none

REPLACE_AWK+=	*.awk
REPLACE_PERL+=	*.pl

NO_BUILD=	yes

INSTALLATION_DIRS+=	bin

do-install:
.for file in	aix-perf \
		difffolded \
		files \
		flamegraph \
		pkgsplit-perf \
		range-perf \
		stackcollapse-aix \
		stackcollapse-elfutils \
		stackcollapse-gdb \
		stackcollapse-go \
		stackcollapse-instruments \
		stackcollapse-jstack \
		stackcollapse-perf \
		stackcollapse-pmc \
		stackcollapse-recursive \
		stackcollapse-stap \
		stackcollapse-vsprof \
		stackcollapse-vtune \
		stackcollapse
	${RUN} cd ${WRKSRC} && ${INSTALL_SCRIPT} \
		${file}.pl \
		${DESTDIR}${PREFIX}/bin/flamegraph-${file}
.endfor
.for file in	stackcollapse-ljp
	${RUN} cd ${WRKSRC} && ${INSTALL_SCRIPT} \
		${file}.awk \
		${DESTDIR}${PREFIX}/bin/flamegraph-${file}
.endfor

.include "../../mk/bsd.pkg.mk"
