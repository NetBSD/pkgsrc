# $NetBSD: Makefile,v 1.4 2016/12/18 22:38:16 joerg Exp $

SCRIPTS=	build build-client-start bulkbuild bulkbuild-rebuild \
		bulkbuild-restart \
		client-clean client-prepare \
		pkg-build pkg-up-to-date pre-build report \
		scan scan-client-start upload \
		compute-packages.awk create-broken-graph.awk \
		create-report-html.awk create-report-txt.awk \
		create-report.awk

SCRIPTSDIR=			${PREFIX}/libexec/pbulk
SCRIPTSDIR_bulkbuild=		${PREFIX}/bin
SCRIPTSDIR_bulkbuild-rebuild=	${PREFIX}/bin
SCRIPTSDIR_bulkbuild-restart=	${PREFIX}/bin

.include <bsd.prog.mk>
