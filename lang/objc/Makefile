# $NetBSD: Makefile,v 1.5 2005/05/15 19:28:37 jlam Exp $

DISTNAME=	objc-3.2.6
CATEGORIES=	lang
MASTER_SITES=	http://users.pandora.be/stes/
DISTFILES=	${DIST_BS}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://users.pandora.be/stes/compiler.html
COMMENT=	Portable Object Compiler

DIST_BS=	objc-bootstrap-3.1.33
WRKSRC_BS=	${WRKDIR}/${DIST_BS}

CONFIGURE_DIRS=		${WRKSRC_BS} ${WRKSRC}
PREPEND_PATH+=		${WRKSRC_BS}
BUILD_TARGET=		default

USE_GNU_TOOLS+=		lex
USE_TOOLS+=		yacc
CONFIGURE_ENV+=		YACC=${TOOLS_YACC:Q}
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

pre-configure:
	${ECHO} >> ${WRKSRC_BS}/configure \
	'${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} -f ${MAKEFILE} ${BUILD_TARGET}'

post-configure:
	${LN} -s . ${WRKSRC_BS}/bin
	${SED} < ${WRKSRC_BS}/objc > ${WRKDIR}/oc.tmp \
		-e 's|${PREFIX}|${WRKSRC_BS}|g'
	${MV} ${WRKDIR}/oc.tmp ${WRKSRC_BS}/objc
	${CHMOD} +x ${WRKSRC_BS}/objc

.include "../../mk/bsd.pkg.mk"
