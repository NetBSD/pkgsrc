# $NetBSD: Makefile,v 1.9 2004/06/23 15:54:08 minskim Exp $
#

DISTNAME=	py152
PKGNAME=	python15-1.5.2
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://www.python.org/ftp/python/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

WRKSRC=		${WRKDIR}/Python-1.5.2
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--without-thread

INSTALL_TARGET=	altinstall

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" || ${OPSYS} == "IRIX"
PY_PLATNAME=	${LOWER_OPSYS}
.else
PY_PLATNAME=	${LOWER_OPSYS}${OS_VERSION:C/\..*//}
.endif
PLIST_SUBST+=	PY_PLATNAME=${PY_PLATNAME}

post-patch:
	${RM} -f ${WRKSRC}/Lib/test/test_fcntl.py.orig

.include "../../mk/bsd.pkg.mk"
