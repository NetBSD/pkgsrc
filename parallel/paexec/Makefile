# $NetBSD: Makefile,v 1.21 2019/06/22 11:52:32 nia Exp $
#

DISTNAME=	paexec-1.1.1
CATEGORIES=	parallel sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=paexec/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/paexec
COMMENT=	Distributes tasks over network or CPUs
LICENSE=	mit

BUILD_DEPENDS+=		mk-configure>=0.27.0:../../devel/mk-configure
DEPENDS+=		runawk>=1.4.3:../../lang/runawk

REPLACE_INTERPRETER+=	runawk
REPLACE.runawk.old=	/usr/bin/env runawk
REPLACE.runawk.new=	${PREFIX}/bin/runawk
REPLACE_FILES.runawk=	paexec/paexec_reorder

TEST_TARGET=		test

EGDIR=			${PREFIX}/share/examples/${PKGBASE}

MAKE_ENV+=		AWK=${AWK:Q}
MAKE_ENV+=		EGDIR=${EGDIR}

BUILD_TARGET=		all doc examples
INSTALL_TARGET=		install install-doc install-examples

REPLACE_SH+=		examples/cc_wrapper/cc_wrapper_cmd \
			tests/broken_echo/transport_broken_echo2

post-install:
	set -e; cd ${WRKSRC}; \
	${INSTALL_DATA} presentation/paexec.pdf ${DESTDIR}${PREFIX}/share/doc/paexec/

.include "../../devel/mk-configure/mk-c.mk"
.include "../../mk/bsd.pkg.mk"
