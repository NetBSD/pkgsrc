# $NetBSD: options.mk,v 1.2 2013/11/17 17:13:29 minskim Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tex-texdoc
PKG_SUPPORTED_OPTIONS+=	x11
PKG_SUGGESTED_OPTIONS+=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11
.if !empty(PKG_OPTIONS:Mx11)
DEPENDS+=	p5-Tk-[0-9]*:../../x11/p5-Tk

PLIST.x11=	yes
REPLACE_PERL=	bin/texdoctk

extract-texdoctk:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/texdoctk/texdoctk.pl \
		${WRKSRC}/bin/texdoctk
	${RMDIR} ${WRKSRC}/texmf-dist/scripts/texdoctk
.else
extract-texdoctk:
	${RM} -rf ${WRKSRC}/texmf-dist/scripts/texdoctk
.endif
