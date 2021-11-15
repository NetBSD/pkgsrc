# $NetBSD: plist-nls.awk,v 1.1 2021/11/15 17:11:57 kim Exp $
BEGIN { NLSDIR = getenv_or_die("NLSDIR") }
{ sub(/^share\/locale\//, NLSDIR "/") }
