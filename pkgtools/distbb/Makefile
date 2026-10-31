# $NetBSD: Makefile,v 1.28 2026/10/31 13:18:40 wiz Exp $

DISTNAME=	distbb-0.49.1
CATEGORIES=	pkgtools
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/cheusov/distbb/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/cheusov/distbb
COMMENT=	DISTributed Bulk Build tool for pkgsrc
LICENSE=	2-clause-bsd

DEPENDS+=	pkg_summary-utils>=0.69.1:../../pkgtools/pkg_summary-utils
DEPENDS+=	paexec>=1.1.6:../../parallel/paexec
DEPENDS+=	runawk>=1.1.0:../../lang/runawk
DEPENDS+=	digest-[0-9]*:../../pkgtools/digest

TOOL_DEPENDS+=	mk-configure>=0.39:../../devel/mk-configure

USE_LANGUAGES=		# none
USE_TOOLS+=		pod2man

REPLACE_SH+=		distbb.in distbb_diff.in slave.in stage_*.in

REPLACE_INTERPRETER+=	runawk
REPLACE.runawk.old=	/usr/bin/env runawk
REPLACE.runawk.new=	${PREFIX}/bin/runawk
REPLACE_FILES.runawk=	gen_weights.in pkg_summary2build_deps.in \
			distbb_grep.in gen_queue.in

EGDIR=			${PREFIX}/share/examples/distbb
DOCDIR=			${PREFIX}/share/doc/distbb

CONF_FILES=		${EGDIR}/distbb.conf     ${PKG_SYSCONFDIR}/distbb.conf
CONF_FILES+=		${EGDIR}/distbb.local.mk ${PKG_SYSCONFDIR}/distbb.local.mk

MAKE_FLAGS+=		EGDIR=${EGDIR}

INSTALLATION_DIRS=	${DOCDIR}

post-install:
.for f in TUTORIAL.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor

.include "../../devel/mk-configure/mk-c.mk"

.include "../../mk/bsd.pkg.mk"
