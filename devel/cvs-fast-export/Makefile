# $NetBSD: Makefile,v 1.2 2013/05/26 01:52:40 ryoon Exp $
#

DISTNAME=	cvs-fast-export-0.4
CATEGORIES=	devel
MASTER_SITES=	http://www.catb.org/~esr/cvs-fast-export/

MAINTAINER=	apb@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/cvs-fast-export/
COMMENT=	Export an RCS or CVS history as a fast-import stream
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	lex yacc
BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

.include "../../mk/bsd.pkg.mk"
