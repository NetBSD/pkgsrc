# $NetBSD: test-libdir_usr_lib_slashdot.sh,v 1.1.2.2 2008/07/13 18:54:18 schmonz Exp $
#

atf_test_case libdir_usr_lib_slashdot
libdir_usr_lib_slashdot_head() {
    atf_set 'descr' 'XXX autoconverted from libdir-usr-lib-slashdot.mk'
}
libdir_usr_lib_slashdot_body() {
    input="-L/usr/lib/."
    echo > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case libdir_usr_lib_slashdot
}
