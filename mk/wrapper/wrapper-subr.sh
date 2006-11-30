# $NetBSD: wrapper-subr.sh,v 1.7 2006/11/30 12:59:56 rillig Exp $
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

# usage: transform_to_and_split "newarg"
transform_to_and_split() {
	arg="$1"
	$debug_log $wrapperlog "    ($wrapsubr_name) to: $1 [split]"
	addtocache=yes
	split_arg=yes
}

# usage: transform_discard
transform_discard() {
	$debug_log $wrapperlog "    ($wrapsubr_name) discarded: $arg"
	arg=""
	addtocache=yes
	split_arg=yes
}

# usage: transform_discard_with_warning [warning]
transform_discard_with_warning() {
	_warning=${1-"discarding option $arg"}
	msg_log "$wrapperlog" "WARNING: [$wrapsubr_name] $_warning"
	transform_discard
	addtocache=no
}

# usage: transform_pass
transform_pass() {
	$debug_log $wrapperlog "    ($wrapsubr_name) to: $arg [unchanged]"
	addtocache=yes
}

# usage: transform_pass_with_warning [warning]
transform_pass_with_warning() {
	_warning=${1-"passing option $arg"}
	msg_log "$wrapperlog" "WARNING: [$wrapsubr_name] $_warning"
	$debug_log $wrapperlog "    ($wrapsubr_name) to: $arg [unchanged]"
	addtocache=no
}
