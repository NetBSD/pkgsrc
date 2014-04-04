# $NetBSD: Makefile,v 1.6 2014/04/04 20:20:42 ryoon Exp $
#

DISTNAME=	cvs-fast-export-1.10
CATEGORIES=	devel
MASTER_SITES=	http://www.catb.org/~esr/cvs-fast-export/

MAINTAINER=	apb@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/cvs-fast-export/
COMMENT=	Export an RCS or CVS history as a fast-import stream
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	flex yacc
BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

REPLACE_PYTHON+=	cvssync

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
