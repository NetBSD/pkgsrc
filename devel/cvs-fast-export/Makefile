# $NetBSD: Makefile,v 1.5 2014/03/10 19:47:34 ryoon Exp $
#

DISTNAME=	cvs-fast-export-1.9
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
