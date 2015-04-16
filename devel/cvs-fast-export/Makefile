# $NetBSD: Makefile,v 1.8 2015/04/16 23:05:06 ryoon Exp $
#

DISTNAME=	cvs-fast-export-1.30
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
