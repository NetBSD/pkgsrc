# $NetBSD: test-rpath_usr_lib_slashdot.sh,v 1.1.2.2 2008/07/13 18:54:18 schmonz Exp $
#

atf_test_case rpath_usr_lib_slashdot
rpath_usr_lib_slashdot_head() {
    atf_set 'descr' 'XXX autoconverted from rpath-usr-lib-slashdot.mk'
}
rpath_usr_lib_slashdot_body() {
    input="${COMPILER_RPATH_FLAG}/usr/lib/."
    echo > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case rpath_usr_lib_slashdot
}
