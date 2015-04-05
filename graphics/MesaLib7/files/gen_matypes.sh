#!/bin/sh
#
# $NetBSD: gen_matypes.sh,v 1.1 2015/04/05 17:01:37 tnn Exp $

test_condition() {
	cat > gen_matypes_cross.c << EOF
#include "main/glheader.h"
#include "main/mtypes.h"
#include "tnl/t_context.h"

#undef offsetof
#define offsetof( type, member ) ((size_t) &((type *)0)->member)

int test_variable[($1) ? 1 : -1];
EOF
	${CC} -c -o /dev/null ${CFLAGS} gen_matypes_cross.c > /dev/null 2>&1
}

compute_powers(){
	local cur
	local i
	cur=1
	i=1
	while [ ${i} -le 16 ]; do
		power_of_two="${cur} ${power_of_two}"
		cur=`expr ${cur} + ${cur}`
		i=`expr ${i} + 1`
	done
}

compute_powers

offset() {
	local got_mismatch
	local bits
	local o
	o=0
	got_mismatch=0
	for bits in ${power_of_two}; do
		if test_condition "offsetof($2, $3) >= $o + $bits"; then
			o=`expr $o + $bits`
		else
			got_mismatch=1
		fi
	done
	[ "$got_mismatch" = 0 ] && exit 1
	printf "#define %s\t%d\n" "$1" $o
}

offset_header() {
	printf "\n"
	printf "\n"
	printf "/* =============================================================\n"
	printf " * Offsets for %s\n" "$1"
	printf " */\n"
	printf "\n"
}

define_header() {
	printf "\n"
	printf "/*\n"
	printf " * Flags for %s\n" "$1"
	printf " */\n"
	printf "\n"
}

define() {
	local bits
	local v
	v=0
	for bits in ${power_of_two}; do
		if test_condition "$2 >= $v + $bits"; then
			v=`expr $v + $bits`
		fi
	done
	printf "#define %s\t0x%x\n" "$1" $v
}

sizeof() {
	local got_mismatch
	local bits
	local v
	v=0
	got_mismatch=0
	for bits in ${power_of_two}; do
		if test_condition "sizeof($2) >= $v + $bits"; then
			v=`expr $v + $bits`
		else
			got_mismatch=1
		fi
	done
	[ "$got_mismatch" = 0 ] && exit 1
	printf "#define %s\t0x%x\n" "$1" $v
}

awk -f gen_matypes.awk < gen_matypes.c > gen_matypes_tmp.sh
. ./gen_matypes_tmp.sh
rm gen_matypes_tmp.sh
