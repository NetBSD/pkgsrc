# $NetBSD: Makefile,v 1.14 2018/09/26 23:19:05 schmonz Exp $

DISTNAME=	cvs-fast-export-1.44
CATEGORIES=	devel
MASTER_SITES=	http://www.catb.org/~esr/cvs-fast-export/

MAINTAINER=	apb@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/cvs-fast-export/
COMMENT=	Export an RCS or CVS history as a fast-import stream
LICENSE=	gnu-gpl-v2

# Race conditions in a2x invocations
MAKE_JOBS_SAFE=	no

USE_LANGUAGES=	c99
USE_TOOLS+=	flex gmake yacc
BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

REPLACE_PYTHON+=	cvsconvert cvssync

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
