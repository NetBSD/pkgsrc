# $NetBSD: Makefile,v 1.15 2014/07/13 16:25:28 cheusov Exp $
#

DISTNAME=	paexec-1.0.0
CATEGORIES=	parallel sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=paexec/} \
		http://mova.org/~cheusov/pub/paexec/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/paexec
COMMENT=	Distributes tasks over network or CPUs
LICENSE=	mit

BUILD_DEPENDS+=		mk-configure>=0.20.0:../../devel/mk-configure
DEPENDS+=		runawk>=1.4.3:../../lang/runawk

REPLACE_INTERPRETER+=	runawk
REPLACE.runawk.old=	/usr/bin/env runawk
REPLACE.runawk.new=	${PREFIX}/bin/runawk
REPLACE_FILES.runawk=	paexec/paexec_reorder

TEST_TARGET=		test

EGDIR=			${PREFIX}/share/examples/${PKGBASE}

MAKE_ENV+=		AWK=${AWK:Q}
MAKE_ENV+=		SUBPRJ_DFLT="paexec doc examples"
MAKE_ENV+=		EGDIR=${EGDIR}

REPLACE_SH+=		examples/cc_wrapper/cc_wrapper_cmd \
			tests/broken_echo/transport_broken_echo2

post-install:
	set -e; cd ${WRKSRC}; \
	${INSTALL_DATA} presentation/paexec.pdf ${DESTDIR}${PREFIX}/share/doc/paexec/

.include "../../devel/mk-configure/mk-c.mk"
.include "../../mk/bsd.pkg.mk"
