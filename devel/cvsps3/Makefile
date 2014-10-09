# $NetBSD: Makefile,v 1.6 2014/10/09 14:06:08 wiz Exp $
#

DISTNAME=	cvsps-3.10
PKGNAME=	${DISTNAME:S/cvsps-/cvsps3-/}
CATEGORIES=	devel scm
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/cvsps/
COMMENT=	Generates 'patchset' information from a CVS repository
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc

USE_TOOLS+=		gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

LIBS.SunOS+=		-lnsl -lsocket
MAKE_ENV+=		LDLIBS=${LIBS:Q}
MAKE_ENV+=		prefix=${PREFIX}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
