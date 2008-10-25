# $NetBSD: options.mk,v 1.2 2008/10/25 18:11:16 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opengrok

PKG_SUPPORTED_OPTIONS=	svn opengrok-build

.include "../../mk/bsd.options.mk"

###
### Support Subversion revision control
###
.if !empty(PKG_OPTIONS:Msvn)
.  include "../../devel/subversion-base/buildlink3.mk"
BUILDLINK_API_DEPENDS.subversion-base+= subversion-base>=1.3.0
.endif

###
### Rebuild OpenGrok
###
.if !empty(PKG_OPTIONS:Mopengrok-build)
DEPENDS+=	jflex-[0-9]*:../../devel/jflex
DEPENDS+=	apache-ant-[0-9]*:../../devel/apache-ant
USE_JAVA=	yes

OPENGROK_SOURCES=	${PKGNAME_NOREV}-src${EXTRACT_SUFX}
DISTFILES+=		${OPENGROK_SOURCES}
EXTRACT_ONLY+=		${OPENGROK_SOURCES}
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}-src
.endif
