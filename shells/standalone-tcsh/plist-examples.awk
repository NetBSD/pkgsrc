# $NetBSD: plist-examples.awk,v 1.1 2021/11/15 17:11:57 kim Exp $
BEGIN { EGDIR = getenv_or_die("EGDIR") }
{ sub(/^share\/examples\/tcsh\//, EGDIR "/") }
