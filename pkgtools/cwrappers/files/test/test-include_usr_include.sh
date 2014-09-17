# $NetBSD: test-include_usr_include.sh,v 1.1 2014/09/17 12:40:56 joerg Exp $
#

atf_test_case include_usr_include
include_usr_include_head() {
    atf_set 'descr' 'XXX autoconverted from include-usr-include.mk'
}
include_usr_include_body() {
    wrapper_test_setup cc
    input="-I/usr/include"
    echo > expout
    atf-check -s eq:0 -o file:expout -e ignore ${WRAPPER} ${input} \
	|| atf_fail 'XXX no reason'
}

atf_test_case include_usr_include_slashdot
include_usr_include_slashdot_head() {
    atf_set 'descr' 'XXX autoconverted from include-usr-include-slashdot.mk'
}
include_usr_include_slashdot_body() {
    wrapper_test_setup cc
    input="-I/usr/include/."
    echo > expout
    atf-check -s eq:0 -o file:expout -e ignore ${WRAPPER} ${input} \
	|| atf_fail 'XXX no reason'
}

atf_test_case include_usr_include_subdir
include_usr_include_subdir_head() {
    atf_set 'descr' 'XXX autoconverted from include-usr-include-subdir.mk'
}
include_usr_include_subdir_body() {
    wrapper_test_setup cc
    input="-I/usr/include/krb5"
    echo "-I/usr/include/krb5" > expout
    atf-check -s eq:0 -o file:expout -e ignore ${WRAPPER} ${input} \
	|| atf_fail 'XXX no reason'
}

atf_init_test_cases() {
    . $(atf_get_srcdir)/setup_common.sh
    atf_add_test_case include_usr_include
    atf_add_test_case include_usr_include_slashdot
    atf_add_test_case include_usr_include_subdir
}
