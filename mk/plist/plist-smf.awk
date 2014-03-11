# $NetBSD: plist-smf.awk,v 1.1 2014/03/11 14:07:04 jperkin Exp $
#
# Handle legacy entries, e.g. in pkgsrc-wip.
#

/^share\/examples\/rc\.d/ {
	next;
}
