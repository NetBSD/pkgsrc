# $NetBSD: Makefile,v 1.4 2014/02/26 10:29:27 wiedi Exp $
#

DISTNAME=	cvs-fast-export-0.5
CATEGORIES=	devel
MASTER_SITES=	http://www.catb.org/~esr/cvs-fast-export/

MAINTAINER=	apb@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/cvs-fast-export/
COMMENT=	Export an RCS or CVS history as a fast-import stream
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	flex yacc
BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

.include "../../mk/bsd.pkg.mk"
