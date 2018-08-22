# $NetBSD: Makefile,v 1.19 2018/08/22 09:46:36 wiz Exp $

VERS=		1.3.2
DISTNAME=	munin_${VERS}
PKGNAME=	munin-doc-${VERS}
PKGREVISION=	8
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=munin/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://munin-monitoring.org/
COMMENT=	System monitoring tool, documentation
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	htmldoc>=0:../../www/htmldoc
BUILD_DEPENDS+= html2text>=0:../../textproc/html2text

USE_TOOLS+=	perl pod2man
USE_TOOLS+=	gmake
USE_PKGINSTALL=	YES

WRKSRC=		${WRKDIR}/${DISTNAME:S:_:-:}

INSTALL_TARGET=	install-doc install-man

BUILD_TARGET=	build-doc build-man

MAKE_ENV+=	PERL5=${PERL5:Q}
MAKE_FLAGS+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}
CHECK_PORTABILITY_SKIP+=	node/node.d/*

PYTHON_FOR_BUILD_ONLY=	yes

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
