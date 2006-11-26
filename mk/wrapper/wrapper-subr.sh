# $NetBSD: wrapper-subr.sh,v 1.3 2006/11/26 09:13:44 rillig Exp $
#
# This file contains shell functions that are useful to the wrapper
# scripts.
#

# usage: transform_setname "current-file"
transform_setname() {
	wrapsubr_name="$1"
}

# usage: transform_to "newarg"
transform_to() {
	arg="$1"
	$debug_log $wrapperlog "    ($wrapsubr_name) to: $1"
	addtocache=yes
}

# usage: transform_to_nocache "newarg"
transform_to_nocache() {
	arg="$1"
	$debug_log $wrapperlog "    ($wrapsubr_name) to: $1"
	addtocache=no
}

# usage: transform_discard
transform_discard() {
	transform_to ""
}

# usage: transform_pass
transform_pass() {
	addtocache=yes
}

# usage: transform_pass_unknown
transform_pass_unknown() {
	msg_log "$wrapperlog" "[$wrapsubr_name] warning: unknown option $arg"
	addtocache=no
}
