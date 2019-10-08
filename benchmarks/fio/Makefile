# $NetBSD: Makefile,v 1.5 2019/10/08 18:13:32 maya Exp $

DISTNAME=	fio-3.16
CATEGORIES=	benchmarks
MASTER_SITES=	http://brick.kernel.dk/snaps/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://git.kernel.dk/?p=fio.git;a=summary
COMMENT=	Flexible IO Tester
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_TOOLS+=	bash gmake lex yacc

DOCDIR=		${PREFIX}/share/doc/fio
EGDIR=		${PREFIX}/share/examples/fio

CONFIGURE_ARGS+=	--prefix=${PREFIX}

REPLACE_BASH+=		tools/genfio
REPLACE_PYTHON+=	tools/fio_jsonplus_clat2csv
REPLACE_PYTHON+=	tools/fio_latency2csv.py
REPLACE_PYTHON+=	tools/fiologparser.py
REPLACE_PYTHON+=	tools/hist/fiologparser_hist.py
REPLACE_PYTHON+=	tools/plot/fio2gnuplot

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR}

TEST_TARGET=		test

post-install:
	${INSTALL_DATA} ${WRKSRC}/HOWTO ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.fio ${DESTDIR}${EGDIR}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
