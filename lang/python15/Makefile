# $NetBSD: Makefile,v 1.12 2005/01/30 12:44:39 jmmv Exp $
#

DISTNAME=	py152
PKGNAME=	python15-1.5.2
PKGREVISION=	3
CATEGORIES=	lang python
MASTER_SITES=	http://www.python.org/ftp/python/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

CONFLICTS+=	python-[0-9]*

WRKSRC=		${WRKDIR}/Python-1.5.2
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--without-thread

INSTALL_TARGET=	altinstall

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=      ${.CURDIR}/../../lang/python15/PLIST.common
.if exists(${.CURDIR}/../../lang/python15/PLIST.${OPSYS})
PLIST_SRC+=     ${.CURDIR}/../../lang/python15/PLIST.${OPSYS}
.endif
PLIST_SRC+=     ${.CURDIR}/../../lang/python15/PLIST.common_end

.if ${OPSYS} == "Darwin"
PY_PLATNAME=	${LOWER_OPSYS}
.elif ${OPSYS} == "IRIX"
PY_PLATNAME=	${LOWER_OPSYS:C/\..*//}
.else
PY_PLATNAME=	${LOWER_OPSYS}${OS_VERSION:C/\..*//}
.endif
PLIST_SUBST+=	PY_PLATNAME=${PY_PLATNAME}

post-patch:
	${RM} -f ${WRKSRC}/Lib/test/test_fcntl.py.orig

.include "../../mk/bsd.pkg.mk"
