# $NetBSD: Makefile,v 1.3 2004/04/27 03:09:58 snj Exp $
#

DISTNAME=		PQueue-0.2
PKGNAME=		${PYPKGPREFIX}-pqueue-0.2
CATEGORIES=		devel
MASTER_SITES=	http://www.csse.monash.edu.au/hons/projects/1999/Andrew.Snare/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=	http://www.csse.monash.edu.au/hons/projects/1999/Andrew.Snare/
COMMENT=		Priority-queues using fibonacci heaps

WRKSRC=		${WRKDIR}/PQueue
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}
ALL_TARGET=		default

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

PYQ_DOCDIR=	${PREFIX}/share/doc/${PYPKGPREFIX}-PQueue

post-install:
	${INSTALL_DATA_DIR} ${PYQ_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${PYQ_DOCDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
