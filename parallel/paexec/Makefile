# $NetBSD: Makefile,v 1.6 2011/10/09 10:02:45 cheusov Exp $
#

DISTNAME=	paexec-0.16.1
PKGREVISION=	1
CATEGORIES=	parallel sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=paexec/} \
		http://mova.org/~cheusov/pub/paexec/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/paexec
COMMENT=	Distributes tasks over network or CPUs
LICENSE=	mit

BUILD_DEPENDS+=		mk-configure>=0.20.0:../../devel/mk-configure
DEPENDS+=		runawk>=0.20.0:../../lang/runawk

PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_INTERPRETER+=	runawk
REPLACE.runawk.old=	/usr/bin/env runawk
REPLACE.runawk.new=	${PREFIX}/bin/runawk
REPLACE_FILES.runawk=	paexec/paexec_reorder

TEST_TARGET=		test

EGDIR=			${PREFIX}/share/examples/${PKGBASE}

MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=		AWK=${AWK:Q}
MAKE_ENV+=		SUBPRJ_DFLT="paexec doc examples"
MAKE_ENV+=		EGDIR=${EGDIR}

REPLACE_SH+=		examples/cc_wrapper/cc_wrapper_cmd \
			tests/broken_echo/transport_broken_echo2

MAKE_PROGRAM=		${PREFIX}/bin/mkcmake

.include "../../devel/mk-configure/configure.mk"

.include "../../devel/libmaa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
