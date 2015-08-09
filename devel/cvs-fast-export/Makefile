# $NetBSD: Makefile,v 1.9 2015/08/09 17:43:41 ryoon Exp $
#

DISTNAME=	cvs-fast-export-1.32
CATEGORIES=	devel
MASTER_SITES=	http://www.catb.org/~esr/cvs-fast-export/

MAINTAINER=	apb@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/cvs-fast-export/
COMMENT=	Export an RCS or CVS history as a fast-import stream
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	flex gmake yacc
BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

REPLACE_PYTHON+=	cvsconvert cvssync

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
