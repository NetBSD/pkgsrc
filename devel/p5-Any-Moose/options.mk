# $NetBSD: options.mk,v 1.3 2023/06/06 12:40:41 riastradh Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.p5-Any-Moose
PKG_OPTIONS_REQUIRED_GROUPS=	backend
PKG_OPTIONS_GROUP.backend=	moose mouse
PKG_SUGGESTED_OPTIONS=		moose

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmoose)
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
TOOL_DEPENDS+=	p5-MooseX-Types>=0.44nb2:../../devel/p5-MooseX-Types
.endif

.if !empty(PKG_OPTIONS:Mmouse)
DEPENDS+=	p5-Mouse-[0-9]*:../../devel/p5-Mouse
TOOL_DEPENDS+=	p5-MouseX-Types-[0-9]*:../../devel/p5-MouseX-Types
.endif
