# $NetBSD: Makefile,v 1.3 2008/04/04 17:58:59 joerg Exp $

SCRIPTS=	build build-client-start bulkbuild bulkbuild-rebuild \
		bulkbuild-restart \
		client-clean pkg-build pkg-up-to-date pre-build report \
		scan scan-client-start upload \
		compute-packages.awk create-broken-graph.awk \
		create-report-html.awk create-report-txt.awk \
		create-report.awk

SCRIPTSDIR=			${PREFIX}/libexec/pbulk
SCRIPTSDIR_bulkbuild=		${PREFIX}/bin
SCRIPTSDIR_bulkbuild-rebuild=	${PREFIX}/bin
SCRIPTSDIR_bulkbuild-restart=	${PREFIX}/bin

.include <bsd.prog.mk>
