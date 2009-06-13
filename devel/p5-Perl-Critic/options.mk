# $NetBSD: options.mk,v 1.2 2009/06/13 06:46:46 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-Perl-Critic
PKG_SUPPORTED_OPTIONS=	file-homedir file-which perl-tidy pod-spell readonly-xs regexp-parser
PKG_SUGGESTED_OPTIONS=	pod-spell readonly-xs regexp-parser

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfile-homedir)
DEPENDS+=	p5-File-HomeDir>=0:../../devel/p5-File-HomeDir
.endif
.if !empty(PKG_OPTIONS:Mfile-which)
DEPENDS+=	p5-File-Which>=0:../../devel/p5-File-Which
.endif
.if !empty(PKG_OPTIONS:Mperl-tidy)
DEPENDS+=	p5-Perl-Tidy>=0:../../devel/p5-Perl-Tidy
.endif
.if !empty(PKG_OPTIONS:Mpod-spell)
DEPENDS+=	p5-Pod-Spell>=1:../../textproc/p5-Pod-Spell
.endif
.if !empty(PKG_OPTIONS:Mreadonly-xs)
DEPENDS+=	p5-Readonly-XS>=0:../../devel/p5-Readonly-XS
.endif
.if !empty(PKG_OPTIONS:Mregexp-parser)
DEPENDS+=	p5-Regexp-Parser>=0.20:../../devel/p5-Regexp-Parser
.endif
