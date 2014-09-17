# $NetBSD: test-option.sh,v 1.1 2014/09/17 12:40:56 joerg Exp $
#

atf_test_case preserve_option
preserve_option_head() {
    atf_set 'descr' 'XXX autoconverted from preserve-option.mk'
}
preserve_option_body() {
    wrapper_test_setup cc
    input="-O2ABC"
    echo "-O2ABC" > expout
    atf-check -s eq:0 -o file:expout -e ignore ${WRAPPER} ${input} \
	|| atf_fail 'XXX no reason'
}

atf_test_case remove_option
remove_option_head() {
    atf_set 'descr' 'XXX autoconverted from remove-option.mk'
}
remove_option_body() {
    wrapper_test_setup cc
    input="-O2 -O5 -O9"
    echo > expout
    atf-check -s eq:0 -o file:expout -e ignore ${WRAPPER} ${input} \
	|| atf_fail 'XXX no reason'
}

atf_init_test_cases() {
    . $(atf_get_srcdir)/setup_common.sh
    atf_add_test_case preserve_option
    atf_add_test_case remove_option
}
