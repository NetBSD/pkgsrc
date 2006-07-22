# $NetBSD: Makefile,v 1.16 2006/07/22 00:36:19 minskim Exp $
#

DISTNAME=	py152
PKGNAME=	python15-1.5.2
PKGREVISION=	4
CATEGORIES=	lang python
MASTER_SITES=	http://www.python.org/ftp/python/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

CONFLICTS+=	python-[0-9]*

WRKSRC=		${WRKDIR}/Python-1.5.2
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--without-thread

INSTALL_TARGET=	altinstall

REPLACE_INTERPRETER+=	py15
REPLACE.py15.old=	.*python[^ ]*
REPLACE.py15.new=	${PREFIX}/bin/python1.5
REPLACE_FILES.py15=	Lib/cgi.py	# explicitly demanded to be patched

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
PLIST_SUBST+=	PY_PLATNAME=${PY_PLATNAME:Q}

post-patch:
	${RM} -f ${WRKSRC}/Lib/test/test_fcntl.py.orig

.include "../../mk/bsd.pkg.mk"
