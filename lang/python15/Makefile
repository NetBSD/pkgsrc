# $NetBSD: Makefile,v 1.8 2004/06/16 22:57:50 minskim Exp $
#

DISTNAME=	py152
PKGNAME=	python15-1.5.2
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.python.org/ftp/python/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

WRKSRC=		${WRKDIR}/Python-1.5.2
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--without-thread
CONFIGURE_ENV+=		MACHDEP=${LOWER_OPSYS}

INSTALL_TARGET=	altinstall

.include "../../mk/bsd.pkg.mk"
