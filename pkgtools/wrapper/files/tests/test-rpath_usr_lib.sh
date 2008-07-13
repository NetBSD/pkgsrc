# $NetBSD: test-rpath_usr_lib.sh,v 1.1.2.1 2008/07/13 18:47:59 schmonz Exp $
#

atf_test_case rpath_usr_lib
rpath_usr_lib_head() {
    atf_set 'descr' 'XXX autoconverted from rpath-usr-lib.mk'
}
rpath_usr_lib_body() {
    input="${COMPILER_RPATH_FLAG}/usr/lib"
    echo "" > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case rpath_usr_lib
}
