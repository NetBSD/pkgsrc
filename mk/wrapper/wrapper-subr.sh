# $NetBSD: wrapper-subr.sh,v 1.5 2006/11/30 11:40:24 rillig Exp $
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

# usage: transform_discard_with_warning [warning]
transform_discard_with_warning() {
	_warning=${1-"discarding option $arg"}
	msg_log "$wrapperlog" "WARNING: [$wrapsubr_name] $_warning"
	transform_to ""
	addtocache=no
}

# usage: transform_pass
transform_pass() {
	addtocache=yes
}

# usage: transform_pass_with_warning [warning]
transform_pass_with_warning() {
	_warning=${1-"passing option $arg"}
	msg_log "$wrapperlog" "WARNING: [$wrapsubr_name] $_warning"
	addtocache=no
}
