# $NetBSD: Makefile,v 1.11 2009/02/11 19:19:00 joerg Exp $
#

DISTNAME=		PQueue-0.2
PKGNAME=		${PYPKGPREFIX}-pqueue-0.2
PKGREVISION=		1
CATEGORIES=		devel python
MASTER_SITES=	http://www.csse.monash.edu.au/hons/projects/1999/Andrew.Snare/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.csse.monash.edu.au/hons/projects/1999/Andrew.Snare/
COMMENT=		Priority-queues using fibonacci heaps

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/PQueue
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN:Q}
BUILD_TARGET=		default

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX:Q}

PYQ_DOCDIR=	${PREFIX}/share/doc/${PYPKGPREFIX}-PQueue

INSTALLATION_DIRS+=	${PYQ_DOCDIR} ${PYSITELIB}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PYQ_DOCDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
