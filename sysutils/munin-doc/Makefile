# $NetBSD: Makefile,v 1.3 2006/11/12 02:04:59 rillig Exp $
#

DISTNAME=	${PKGNAME:S:-doc-:_:}
PKGNAME=	munin-doc-1.3.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=munin/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://munin.sourceforge.net/
COMMENT=	System monitoring tool, documentation

BUILD_DEPENDS+=	htmldoc>=0:../../www/htmldoc
BUILD_DEPENDS+= html2text>=0:../../textproc/html2text

USE_TOOLS+=	perl
USE_TOOLS+=	gmake
USE_PKGINSTALL=	YES

WRKSRC=		${WRKDIR}/${DISTNAME:S:_:-:}

INSTALL_TARGET=	install-doc install-man

BUILD_TARGET=	build-doc build-man

MAKE_ENV+=	PERL5=${PERL5:Q}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
CHECK_PORTABILITY_SKIP+=	node/node.d/*

.include "../../mk/bsd.pkg.mk"
.include "../../lang/python/application.mk"
