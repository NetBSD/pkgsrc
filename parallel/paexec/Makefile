# $NetBSD: Makefile,v 1.29 2024/06/07 12:27:25 cheusov Exp $
#

DISTNAME=	paexec-1.1.6
CATEGORIES=	parallel sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=paexec/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/cheusov/paexec
COMMENT=	Distributes tasks over network or CPUs
LICENSE=	mit

TOOL_DEPENDS+=		mk-configure>=0.34.0:../../devel/mk-configure
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

post-install:
	set -e; cd ${WRKSRC}; \
	${INSTALL_DATA} presentation/paexec.pdf ${DESTDIR}${PREFIX}/share/doc/paexec/

.include "../../devel/libmaa/buildlink3.mk"
.include "../../devel/mk-configure/mk-c.mk"
.include "../../mk/bsd.pkg.mk"
