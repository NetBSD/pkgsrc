# $NetBSD: test-include_usr_include.sh,v 1.1.2.4 2009/03/30 01:02:26 schmonz Exp $
#

atf_test_case include_usr_include
include_usr_include_head() {
    atf_set 'descr' 'XXX autoconverted from include-usr-include.mk'
}
include_usr_include_body() {
    input="-I/usr/include"
    echo > expout
    atf-check -s eq:0 -o file:expout e ignore 'echowrapper ${input}'
}

atf_test_case include_usr_include_slashdot
include_usr_include_slashdot_head() {
    atf_set 'descr' 'XXX autoconverted from include-usr-include-slashdot.mk'
}
include_usr_include_slashdot_body() {
    input="-I/usr/include/."
    echo > expout
    atf-check -s eq:0 -o file:expout e ignore 'echowrapper ${input}'
}

atf_test_case include_usr_include_subdir
include_usr_include_subdir_head() {
    atf_set 'descr' 'XXX autoconverted from include-usr-include-subdir.mk'
}
include_usr_include_subdir_body() {
    input="-I/usr/include/krb5"
    echo "-I/usr/include/krb5" > expout
    atf-check -s eq:0 -o file:expout e ignore 'echowrapper ${input}'
}

atf_init_test_cases() {
    atf_add_test_case include_usr_include
    atf_add_test_case include_usr_include_slashdot
    atf_add_test_case include_usr_include_subdir
}
