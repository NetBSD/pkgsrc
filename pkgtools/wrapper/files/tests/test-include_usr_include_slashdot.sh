# $NetBSD: test-include_usr_include_slashdot.sh,v 1.1.2.2 2008/07/13 18:54:18 schmonz Exp $
#

atf_test_case include_usr_include_slashdot
include_usr_include_slashdot_head() {
    atf_set 'descr' 'XXX autoconverted from include-usr-include-slashdot.mk'
}
include_usr_include_slashdot_body() {
    input="-I/usr/include/."
    echo > expout
    atf_check 'echowrapper ${input}' 0 expout ignore
}

atf_init_test_cases() {
    atf_add_test_case include_usr_include_slashdot
}
